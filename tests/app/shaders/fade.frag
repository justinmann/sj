uniform mediump float alpha;
uniform sampler2D texture;
varying mediump vec2 v_textureCoordinate;

void main() {
    mediump vec4 color = texture2D(texture, v_textureCoordinate);
    gl_FragColor = vec4(color.rgb, alpha);
}