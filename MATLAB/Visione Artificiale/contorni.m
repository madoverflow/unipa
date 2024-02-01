function img = contorni(img)
%applicazione del filtro gradiente con Sobel
[height,width,sheets] = size(img);
if sheets~=1
    img = rgb2gray(img);
end

%calcolo derivata lungo y: mettere in risalto i contorni orizzontali
kernel1 = [1 0 -1]';
kernel2 = [1 2 1];
dy = conv2(conv2(img,kernel1,"same"),kernel2,"same");
%fine

%calcolo derivata lungo x: mettere in risalto i contorni verticali
kernel1 = [1 2 1]';
kernel2 = [1 0 -1];
dx = conv2(conv2(img,kernel1,"same"),kernel2,"same");
%fine

bordiImg = edge(img);
angoli = atan2(-dy,-dx);
angoli = round(((angoli+pi)/(2*pi))*360)+2;
tavolozzaColori = vertcat([0 0 0],round(hsv(361)*255));
angoli(bordiImg==0)=1;

figure("Name","Immagine");
imshow(img,[0 255]);
figure("Name","Contorni dell'immagine");
imshow(ind2rgb(angoli,tavolozzaColori));
end

