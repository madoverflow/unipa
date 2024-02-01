function out = rotazioneConPuntini(img,angolo)
[height, width, sheets] = size(img);
yVertici = [1,width,1,width]-(width/2);
xVertici = [1,1,height,height]-(height/2);

W = round(max(xVertici*sind(angolo)+yVertici*cosd(angolo))*2);
H = round(max(xVertici*cosd(angolo)-yVertici*sind(angolo))*2);

out = zeros(H,W,sheets);
for j=1:width
    for i=1:height
        x = (i - (height/2)) * cosd(angolo) - (j - (width/2)) * sind(angolo);
        y = (i - (height/2)) * sind(angolo) + (j - (width/2)) * cosd(angolo);
        x = round(x + (H/2));
        y = round(y + (W/2));
        if x >= 1 && x <= H && y >= 1 && y <= W
            for k=1:sheets
                out(x,y,k) = img(i,j,k);
            end
        end
    end
end
out = uint8(out);
figure("Name","Immagine non ruotata");
imshow(img);
figure("Name","Immagine ruotata di "+num2str(angolo)+" gradi");
imshow(out);
end

