function S=simmetriaRadiale(img)

[height, width, levels] = size(img);
%se un'immagine è a colori, viene convertita in scala di grigio
if(levels ~= 1) %a colori vuol dire avere più livelli: rosso, verde, blu
    img = rgb2gray(img);
end
S = zeros(size(img)); %matrice risultato
N=0;
%per non fare il modulo
alpha = 2;
%calcolo dei moduli e degli angoli
%ottimizzare con la separabilità delle variabili
[~, ~, dy, dx] = edge(img, 'sobel');
angoli = atan2(-dy, -dx) + pi;
for r=7:2:13
    O = zeros(size(img)); %matrice di accumulazione per gli angoli
    M = zeros(size(img)); %matrice di accumulazione per i moduli
    for j=r+1:width-r
        for i=r+1:height-r
            %calcolo delle coordinate per direzione positiva e negativa
            %calcolare separatamente coseno e seno
            xp = round(i+cos(angoli(i,j))*r);
            yp = round(j+sin(angoli(i,j))*r);
            xn = round(i-cos(angoli(i,j))*r);
            yn = round(j-sin(angoli(i,j))*r); 
            %

            %popolazione matrici di accumulazione
            O(xp,yp) = O(xp,yp) + 1;
            O(xn,yn) = O(xn,yn) - 1;
            M(xp,yp) = M(xp,yp) + sqrt(dx(i,j)^2 + dy(i,j)^2);
            M(xn,yn) = M(xn,yn) - sqrt(dx(i,j)^2 + dy(i,j)^2);
        end
    end
    %assegnazione della costante al variare del raggio
    if (r==1)
        k=8;
    else
        k=9.9;
    end

    %calcolo della matrice F, matrice che combina il risultato di O ed M
    M = M/k;
    O = (min(O,k)/k).^alpha;
    F = M.*O;

    %convoluzione di F con gaussiano di media r e deviazione standard
    %0.5*r
    %prodotto per r fspecial perché?
    convoluzione = conv2(F, fspecial('gaussian', r, 0.5*r), 'same');
    
    %somma coi risultati ottenuti per gli altri raggi
    S(:,:,1) = S(:,:,1)+convoluzione;
    S(:,:,N+2) = convoluzione;
    N=N+1;
end
%comando mean per farlo.
S(:,:,1)=S(:,:,1)/N;
%figure; imshow(S(:,:,1), []);
for k=1:N+1
    figure; imshow(S(:,:,k), []);
end