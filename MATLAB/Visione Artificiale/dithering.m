function imgQuantizzata = dithering(img,imgQuantizzata)
if(~isequal(size(img),size(imgQuantizzata)))
    disp("Le immagini non hanno le stesse dimensioni. Dunque, una non" + ...
        "può essere la quantizzazione dell'altra");
    return;
end
[height, width, ~] = size(imgQuantizzata);
imgQuantizzata = double(imgQuantizzata);
%finestra 2x2 per fare il dithering. Bordo di 1 pixel sotto e a destra
for j=1:width-1
    for i=1:height-1
        errore = img(i,j) - imgQuantizzata(i,j);
        imgQuantizzata(i+1,j) = imgQuantizzata(i+1,j) + (errore*0.375);
        imgQuantizzata(i,j+1) = imgQuantizzata(i,j+1) + (errore*0.375);
        imgQuantizzata(i+1,j+1) = imgQuantizzata(i+1,j+1) + (errore*0.25);
    end
end
imgQuantizzata = uint8(round(imgQuantizzata));
%figure("Name","Applicazione dithering");
%imshow(imgQuantizzata, [0 255]);
end