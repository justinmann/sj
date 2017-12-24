uniform mediump float sigma;     // The sigma value for the gaussian function: higher value means more blur
                         // A good value for 9x9 is around 3 to 5
                         // A good value for 7x7 is around 2.5 to 4
                         // A good value for 5x5 is around 2 to 3.5
                         // ... play around with this based on what you need :)

uniform mediump float blurSize;  // This should usually be equal to
                         // 1.0f / texture_pixel_width for a horizontal blur, and
                         // 1.0f / texture_pixel_height for a vertical blur.

const mediump float pi = 3.14159265;
const mediump float numBlurPixelsPerSide = 4.0;
const mediump vec2  blurMultiplyVec      = vec2(0.0, 1.0);

// The following are all mutually exclusive macros for various 
// seperable blurs of varying kernel size
// #if defined(VERTICAL_BLUR_9)
// const float numBlurPixelsPerSide = 4.0f;
// const vec2  blurMultiplyVec      = vec2(0.0f, 1.0f);
// #elif defined(HORIZONTAL_BLUR_9)
// const float numBlurPixelsPerSide = 4.0f;
// const vec2  blurMultiplyVec      = vec2(1.0f, 0.0f);
// #elif defined(VERTICAL_BLUR_7)
// const float numBlurPixelsPerSide = 3.0f;
// const vec2  blurMultiplyVec      = vec2(0.0f, 1.0f);
// #elif defined(HORIZONTAL_BLUR_7)
// const float numBlurPixelsPerSide = 3.0f;
// const vec2  blurMultiplyVec      = vec2(1.0f, 0.0f);
// #elif defined(VERTICAL_BLUR_5)
// const float numBlurPixelsPerSide = 2.0f;
// const vec2  blurMultiplyVec      = vec2(0.0f, 1.0f);
// #elif defined(HORIZONTAL_BLUR_5)
// const float numBlurPixelsPerSide = 2.0f;
// const vec2  blurMultiplyVec      = vec2(1.0f, 0.0f);
// #else
// This only exists to get this shader to compile when no macros are defined
// const float numBlurPixelsPerSide = 0.0f;
// const vec2  blurMultiplyVec      = vec2(0.0f, 0.0f);
// #endif

uniform sampler2D texture;
varying mediump vec2 v_textureCoordinate;

void main() {
  // Incremental Gaussian Coefficent Calculation (See GPU Gems 3 pp. 877 - 889)
  mediump vec3 incrementalGaussian;
  incrementalGaussian.x = 1.0 / (sqrt(2.0 * pi) * sigma);
  incrementalGaussian.y = exp(-0.5 / (sigma * sigma));
  incrementalGaussian.z = incrementalGaussian.y * incrementalGaussian.y;

  mediump vec4 avgValue = vec4(0.0, 0.0, 0.0, 0.0);
  mediump float coefficientSum = 0.0;

  // Take the central sample first...
  avgValue += texture2D(texture, v_textureCoordinate.xy) * incrementalGaussian.x;
  coefficientSum += incrementalGaussian.x;
  incrementalGaussian.xy *= incrementalGaussian.yz;

  // Go through the remaining 8 vertical samples (4 on each side of the center)
  for (mediump float i = 1.0; i <= numBlurPixelsPerSide; i++) { 
    avgValue += texture2D(texture, v_textureCoordinate.xy - i * blurSize * blurMultiplyVec) * incrementalGaussian.x;         
    avgValue += texture2D(texture, v_textureCoordinate.xy + i * blurSize * blurMultiplyVec) * incrementalGaussian.x;         
    coefficientSum += 2.0 * incrementalGaussian.x;
    incrementalGaussian.xy *= incrementalGaussian.yz;
  }

  gl_FragColor = avgValue / coefficientSum;
}