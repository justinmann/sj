uniform mediump float amount;
uniform sampler2D texture;
varying mediump vec2 v_textureCoordinate;

void main() {
    mediump vec4 color = texture2D(texture, v_textureCoordinate);
    gl_FragColor = vec4(mix(vec3(dot(color.rgb, vec3(0.2125, 0.7154, 0.0721))), color.rgb, amount), color.a); 
}