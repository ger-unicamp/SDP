%Funcao feita para o Ubuntu versao 16

function port = findSerialPort()
  linux = true;
  
  if (linux)
    address = pwd;
    
    cd /dev;
    
    files = ls;
    
    cd (do_string_escapes(address));
    port = '/dev/ttyACM';

    for raw = 1: size(files,1)
    
      for col = 1: size(files,2)
     
        if (files(raw, col) == 'A' && files(raw, col))
          port(1,(size(port,2) + 1)) = files(raw, col + 3);
        endif
        
      endfor
        
    endfor
  else
    % Descubra olhando no gerenciador de dispositivos.
    port = "\\\\.\\COM4"
  endif
  
  
  
 