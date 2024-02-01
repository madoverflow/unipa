function out = filtroMediano(img,heightFinestra,widthFinestra)
[height,~,sheets] = size(img);
if sheets~=1
    img = rgb2gray(img);
end
lutOrdinamento = zeros(256,1);
[lutF,limiteSinistroRiga,limiteDestroRiga,limiteSinistroColonna,limiteDestroColonna] = lutFinestra(heightFinestra,widthFinestra,height);
out = zeros(size(img));
out((1+limiteSinistroRiga):(end-limiteDestroRiga),(1+limiteSinistroColonna):(end-limiteDestroColonna)) = 1;
posizioni = find(out);
for i=1:length(posizioni)
    for j=1:heightFinestra*widthFinestra
        lutOrdinamento(img(posizioni(i)+lutF(j))+1) = 1;
    end
    posizioniPixelOrdinati = find(lutOrdinamento);
    out(posizioni(i)) = posizioniPixelOrdinati(round(length(posizioniPixelOrdinati)/2))-1;
    lutOrdinamento(:) = 0;
end
%figure("Name","Immagine pre filtro mediano");
%imshow(img,[0 255]);
%figure("Name","Immagine post filtro mediano");
%imshow(out,[0 255]);
end

function [LUT,limiteSinistroRiga,limiteDestroRiga,limiteSinistroColonna,limiteDestroColonna] = lutFinestra(heightFinestra,widthFinestra,height)
limiteSinistroRiga = floor((heightFinestra-1)/2);
limiteDestroRiga = floor(heightFinestra/2);
limiteSinistroColonna = floor((widthFinestra-1)/2);
limiteDestroColonna = floor(widthFinestra/2);
vettoreAltezze = height*horzcat((-limiteSinistroColonna:1:0),(1:limiteDestroColonna));
vettoreNumeri = vertcat((-limiteSinistroRiga:1:0)',(1:limiteDestroRiga)');
LUT = bsxfun(@plus,vettoreNumeri,vettoreAltezze);
LUT = LUT(:);
end

