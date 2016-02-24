#version 120

uniform vec2 resolution;
uniform sampler2DRect texture;
uniform int loopStart;
uniform int loopEnd;

varying vec2 vTexCoord;

void main() {
  vec4 color = vec4(0, 0, 0, 1);
  vec2 center = resolution / 2;
  float len = length(vTexCoord - center);
  float l = loopStart + max(1, len / resolution.x * 2 * loopEnd);

  for(int i = loopStart; i < l; i++) {
    color += texture2DRect(texture, (vTexCoord - center) * pow(0.999, i) + center);
  }

  gl_FragColor = color;
}
