% Returns de array of parameters of adjustment

function parameterArray = getCalibrationParameters(array)
  pixel = 1;
  MAX_WHITE = 255;
  while (pixel <= 128)
    parameterArray(pixel) = MAX_WHITE - array(pixel);
    pixel++;
  endwhile