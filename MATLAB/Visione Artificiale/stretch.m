function stretch(img)
[~,~,sheets] = size(img);
if sheets~=1
    img = rgb2gray(img);
end
if min(img(:))==0 || max(img(:))==255
    disp("E' presente almeno un pixel bianco o nero. Impossibile eseguire" + ...
        " lo streching dell'immgagine");
    return;
end
numeroIstogrammi = 256;
figure("Name","Immagine non stretchata");
imshow(img,[0 255]);
[frequencies,extremes] = imhist(img,numeroIstogrammi);
figure("Name","Istogramma immagine non stretchata");
xlabel("Frequenze");
ylabel("Pixel");
bar(extremes,frequencies);
%inizio lo stretching
img = single(img);
img = img-min(img(:));
img = uint8(round((img/max(img(:)))*255));
[frequencies,extremes] = imhist(img,numeroIstogrammi);
figure("Name","Immagine stretchata");
imshow(img,[0 255]);
figure("Name","Istogramma immagine stretchata");
xlabel("Frequenze");
ylabel("Pixel");
bar(extremes,frequencies);
end

