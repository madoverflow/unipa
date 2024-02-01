function rotazioneSenzaPuntini(img,angolo)
[height, width, sheets] = size(img);
yVertici = [1,width,1,width]-(width/2);
xVertici = [1,1,height,height]-(height/2);

W = round(max(xVertici*sind(angolo)+yVertici*cosd(angolo))*2);
H = round(max(xVertici*cosd(angolo)-yVertici*sind(angolo))*2);

out = zeros(H,W,sheets);
for j=1:W
    for i=1:H
        x = (i - (H/2)) * cosd(angolo) + (j - (W/2)) * sind(angolo);
        y = (j - (W/2)) * cosd(angolo) - (i - (H/2)) * sind(angolo);
        x = round(x + (height/2));
        y = round(y + (width/2));
        if x >= 1 && x <= height && y >= 1 && y <= width
            for k=1:sheets
                out(i,j,k) = img(x,y,k);
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

