function image = naosei(vetor)
  i = 2;
  
  max =1;
  
  % Determina o max global
  while (i <= 128)
    if (vetor(i) > vetor(max))
      max = i;
     endif
     i++;
  endwhile
  display("Maximo: ");
  display(max);
  i = 1;
  maxP = 0.1;
  
  % Lado esquerdo
  while (i < max)
    if (vetor(i) > maxP)
      maxP = vetor(i);
    endif
    
    if ((vetor(i)/maxP) < 0.85 && i != 1)
      display("Posicao:");
      display(i);
    endif
    i++;
    
  endwhile
  i = 128;
  maxP = 0.1;
  % Lado direito
  while (i > max)
    if (vetor(i) > maxP)
      maxP = vetor(i);
    endif
    
    if ((vetor(i)/maxP) < 0.85 && i != 128)
      display("Posicao:");
      display(i);
    endif
    i--;
    
  endwhile