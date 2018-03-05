function image = calibration(array)
  
  MAX_WHITE = 255;
  MIN_BLACK = 0;
  BLACK_WHITE_BORDER = 150;
  
  for pixel = 1:(size(array,2))
    if (array(pixel) < BLACK_WHITE_BORDER)
      image(pixel) = MIN_BLACK;
    else
      image(pixel) = MAX_WHITE;
    endif
        
  endfor