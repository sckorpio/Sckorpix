import { getWebGLContext, getWebGLResourceID } from "../../canvas/utils.js";

class Shader {
  constructor() {
    this.uniqueID = getWebGLResourceID();
    this.shaderName = '';
    this.filePath = '';
    this.vertexShaderSource = '';
    this.fragmentShaderSource = '';
    this.shaderProgram = null;
  }

  // Destructor for cleanup
  dispose() {
    if (this.shaderProgram) {
      const gl = getWebGLContext();
      gl.deleteProgram(this.shaderProgram);
    }
  }

  // Generate Shader Program
  async generate(shaderName) {
    this.shaderProgram = null;
    this.shaderName = shaderName;
    this.filePath = "sckorpix/resources/shaders/" + shaderName + ".txt";

    const source = await this.parseShader(this.filePath);

    const vertexShaderID = this.compileShader(source.vertexSource, 'vertex');
    const fragmentShaderID = this.compileShader(source.fragmentSource, 'fragment');

    this.shaderProgram = this.linkProgram(vertexShaderID, fragmentShaderID);
    this.bind();
  }

  // parsing shader text files
  async parseShader(filepath) {
    const response = await fetch(filepath);
    const shaderCode = await response.text();

    const shaderSource = { vertexSource: '', fragmentSource: '' };
    let type = 'none';

    const lines = shaderCode.split('\n');

    lines.forEach(line => {
      if (line.includes('#shader')) {
        if (line.includes('vertex')) {
          type = 'vertex';
        } else if (line.includes('fragment')) {
          type = 'fragment';
        }
      } else {
        if (type === 'vertex') {
          shaderSource.vertexSource += line + '\n';
        } else if (type === 'fragment') {
          shaderSource.fragmentSource += line + '\n';
        }
      }
    });

    return shaderSource;
  }

  // compile shader
  compileShader(shaderSource, type) {
    const gl = getWebGLContext();
    const shaderType = type === 'vertex' ? gl.VERTEX_SHADER : gl.FRAGMENT_SHADER;

    const shaderID = gl.createShader(shaderType);
    if (!shaderID) {
      console.error(`Failed to create ${type} shader.`);
      return 0;
    }

    gl.shaderSource(shaderID, shaderSource);
    gl.compileShader(shaderID);

    if (!gl.getShaderParameter(shaderID, gl.COMPILE_STATUS)) {
      const errorMessage = gl.getShaderInfoLog(shaderID);
      console.error(`Error compiling ${type} shader:`, errorMessage);
      gl.deleteShader(shaderID);
      return 0;
    }

    return shaderID;
  }

  linkProgram(vertexShaderID, fragmentShaderID) {
    const gl = getWebGLContext();
    const programID = gl.createProgram();

    if (!programID) {
      console.error('Failed to create shader program.');
      return null;
    }

    // Ensure shaders are valid
    if (!vertexShaderID || !fragmentShaderID) {
      console.error('Shaders are not valid or compiled.');
      return null;
    }

    // Attach shaders
    gl.attachShader(programID, vertexShaderID);
    gl.attachShader(programID, fragmentShaderID);

    // Link program
    gl.linkProgram(programID);
    if (!gl.getProgramParameter(programID, gl.LINK_STATUS)) {
      console.error('ERROR linking program!', gl.getProgramInfoLog(programID));
      return null;
    }

    // Validate program
    gl.validateProgram(programID);
    if (!gl.getProgramParameter(programID, gl.VALIDATE_STATUS)) {
      console.error('ERROR validating program!', gl.getProgramInfoLog(programID));
      return null;
    }

    return programID;
  }

  // Bind
  bind() {
    //console.log("Bind() Shader =",this.uniqueID);
    const gl = getWebGLContext();
    if (this.shaderProgram) {
      gl.useProgram(this.shaderProgram);
    }
  }

  // unbind
  unbind() {
    //console.log("UnBind() Shader =",this.uniqueID);
    const gl = getWebGLContext();
    gl.useProgram(null);
  }

  //get AttribLocation from shader
  getAttribLocation(name) {
    const gl = getWebGLContext();
    return gl.getAttribLocation(this.shaderProgram, name);
  }

  // Setters for uniform variables
  setUniform1i(name, value) {
    const gl = getWebGLContext();
    const location = this.getUniformLocation(name);
    gl.uniform1i(location, value);
  }

  setUniform1iv(name, count, value) {
    const gl = getWebGLContext();
    const location = this.getUniformLocation(name);
    gl.uniform1iv(location, value);
  }

  setUniform1f(name, value) {
    const gl = getWebGLContext();
    const location = this.getUniformLocation(name);
    gl.uniform1f(location, value);
  }

  setUniform3f(name, v0, v1, v2) {
    const gl = getWebGLContext();
    const location = this.getUniformLocation(name);
    gl.uniform3f(location, v0, v1, v2);
  }

  setUniform4f(name, v0, v1, v2, v3) {
    const gl = getWebGLContext();
    const location = this.getUniformLocation(name);
    gl.uniform4f(location, v0, v1, v2, v3);
  }

  setUniform3fv(name, vec) {
    const gl = getWebGLContext();
    const location = this.getUniformLocation(name);
    gl.uniform3fv(location, vec);
  }

  setUniformMat4f(name, matrix) {
    const gl = getWebGLContext();
    const location = this.getUniformLocation(name);
    gl.uniformMatrix4fv(location, false, matrix);
  }

  getUniformLocation(name) {
    const gl = getWebGLContext();
    const location = gl.getUniformLocation(this.shaderProgram, name);
    if (location === null) {
      console.error(`${name} - not exist`);
    }
    return location;
  }
}

export {
  Shader
}
