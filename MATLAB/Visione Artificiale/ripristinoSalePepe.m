function ripristinoSalePepe(img)
[height,width,sheets] = size(img);
if sheets~=1
    img = rgb2gray(img);
end
figure("Name","Immagine pre sale e pepe");
imshow(img,[0,255]);
imgRumore = salePepe(img);
figure("Name","Immagine post sale e pepe");
imshow(imgRumore,[0,255]);
imgMediano = filtroMediano(imgRumore,3,3);
figure("Name","Rimozione della maggior parte del rumore");
imshow(imgMediano,[0,255]);
posizioniRumorose = find(imgMediano==255);
disp(posizioniRumorose)
imgMediano(posizioniRumorose) = img(posizioniRumorose);
posizioniRumorose = find(imgMediano==0);
disp(posizioniRumorose)
imgMediano(posizioniRumorose) = img(posizioniRumorose);
figure("Name","Rimozione quasi totale del rumore rimasto");
imshow(imgMediano,[0,255]);
end

