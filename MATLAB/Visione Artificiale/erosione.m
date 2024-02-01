function erosione(img,se)
[height,width,sheets] = size(img);
[heightSE, widthSE, ~] = size(se);
if sheets~=1
    img = rgb2gray(img);
end
if heightSE>height || widthSE>width
    disp("Elemento strutturante più grande dell'immagine. Erosione fallita.");
    return;
end
limiteSinistroRiga = floor((heightSE-1)/2);
limiteDestroRiga = floor(heightSE/2);
limiteSinistroColonna = floor((widthSE-1)/2);
limiteDestroColonna = floor(widthSE/2);
out = zeros(height,width);
out((1+limiteSinistroRiga):(end-limiteDestroRiga),(1+limiteSinistroColonna):(end-limiteDestroColonna)) = 1;
lutS = lutSE(se,height);
vettorePixel = zeros(size(lutS));
indici = find(out);
for j=1:length(indici)
    for i=1:length(vettorePixel)
        vettorePixel(i) = img(indici(j)+lutS(i));
    end
    out(indici(j)) = min(vettorePixel(:));
end
figure("Name","Immagine pre erosione");
imshow(img,[0 255]);
figure("Name","Immagine post erosione");
imshow(out,[0 255]);
end

function LUT = lutSE(se,heightImg)
    [heightSE,widthSE,~] = size(se);
    limiteSinistroH = floor((widthSE-1)/2);
    limiteDestroH = floor((widthSE)/2);
    lutH = heightImg*horzcat(-limiteSinistroH:1:0,1:limiteDestroH);
    limiteSinistroN = floor((heightSE-1)/2);
    limiteDestroN = floor((heightSE)/2);
    lutN = vertcat((-limiteSinistroN:1:0)',(1:limiteDestroN)');
    LUT = bsxfun(@plus,lutN,lutH);
    LUT = LUT(:);
    LUT = LUT(find(se(:)));
end
