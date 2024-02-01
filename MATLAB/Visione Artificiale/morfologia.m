function morfologia(img)
[~,~,sheets] = size(img);
if(sheets ~=1)
   img = rgb2gray(img); 
end
se = strel('disk',10);
figure("Name","Immagine quantizzata");
imshow(img,[0 255]);
figure("Name","Erosione");
imshow(imerode(img,se),[0 255]);
figure("Name","Dilatazione");
imshow(imdilate(img,se),[0 255]);
figure("Name","Apertura");
imshow(imopen(img,se),[0 255]);
figure("Name","Chiusura");
imshow(imclose(img,se),[0 255]);
figure("Name","Operatore K");
imshow(img+imtophat(img,se)-imbothat(img,se),[0 255]);
end

