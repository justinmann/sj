uniform mediump vec3 lightPos;
uniform mediump vec3 specColor;

varying mediump vec3 normalInterp;
varying mediump vec3 vertPos;
varying mediump vec2 textureCoordinate;

uniform sampler2D texture;

void main() {

  mediump vec3 normal = normalize(normalInterp); 
  mediump vec3 lightDir = normalize(lightPos - vertPos);

  mediump float lambertian = max(dot(lightDir, normal), 0.0);
  mediump float specular = 0.0;

  if(lambertian > 0.0) {

    mediump vec3 reflectDir = reflect(-lightDir, normal);
    mediump vec3 viewDir = normalize(-vertPos);

    mediump float specAngle = max(dot(reflectDir, viewDir), 0.0);
    // specular = pow(specAngle, 4.0);

    // the exponent controls the shininess (try mode 2)
    specular = pow(specAngle, 16.0) / 4.0;

    // according to the rendering equation we would need to multiply
    // with the the "lambertian", but this has little visual effect
    // specular *= lambertian;

    // switch to mode 4 to turn off the specular component
    // specular *= 0.0;
  }

  mediump vec4 color = texture2D(texture, textureCoordinate);
  gl_FragColor = vec4(lambertian * color.rgb + specular * specColor.rgb, color.a);
}
