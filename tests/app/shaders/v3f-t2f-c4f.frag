/* Freetype GL - A C OpenGL Freetype engine
 *
 * Distributed under the OSI-approved BSD 2-Clause License.  See accompanying
 * file `LICENSE` for more details.
 */
uniform sampler2D texture;
varying mediump vec2 v_textureCoordinate;
varying mediump vec4 v_color;

void main()
{
    mediump float a = texture2D(texture, v_textureCoordinate).r;
    gl_FragColor = vec4(v_color.rgb, v_color.a*a);
}
