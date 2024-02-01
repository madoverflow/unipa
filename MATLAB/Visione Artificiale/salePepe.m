function img = salePepe(img)
%10\% di rumore così distribuito = 5 sale e 5 pepe
[height,width,sheets] = size(img);
if sheets~=1
    img = rgb2gray(img);
end
percentualeRumore = 20;
permutazione = randperm(height*width,round(((height*width)*percentualeRumore)/100));
%figure("Name","Immagine pre sale e pepe");
%imshow(img,[0,255]);
img(permutazione(1:floor(length(permutazione)/2))) = 255;
img(permutazione(floor(length(permutazione)/2)+1:end)) = 0;
%figure("Name","Immagine post sale e pepe");
%imshow(img,[0,255]);
end

