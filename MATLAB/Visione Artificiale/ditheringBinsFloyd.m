function img = ditheringBinsFloyd(img,nBins)
[height,width,sheets] = size(img);
tavolozzaColori = zeros([1,nBins]);
count = 1;
i = 0;
if(sheets~=1)
    img = single(rgb2gray(img));
end
%calcolo delle medie di ciascun bin
minimo = min(img(:));
massimo = max(img(:));
passo = (massimo-minimo)/nBins;
for i=minimo:passo:massimo-(passo+passo)
    estremoInferiore = round(i);
    estremoSuperiore = round(i+passo);
    posizioni = img>=estremoInferiore & img<estremoSuperiore;
    disp(round(mean(img(posizioni))));
    tavolozzaColori(count) = round(mean(img(posizioni)));
    count = count+1;
end
i = i+passo;
estremoInferiore = round(i);
estremoSuperiore = round(i+passo);
posizioni = img>=estremoInferiore & img<=estremoSuperiore;
disp(round(mean(img(posizioni))));
tavolozzaColori(count) = round(mean(img(posizioni)));
disp(tavolozzaColori);
%--------------------------------------------------------------------------
for j=1:width -1
    for i=1:height -1
        errore = img(i,j) - tavolozzaColori(1);
        for k=2:nBins
            nuovoErrore = abs(img(i,j)-tavolozzaColori(k));
            if nuovoErrore < abs(errore)
                errore = img(i,j) - tavolozzaColori(k);
            end
        end
        img(i,j) = (errore - img(i,j))*-1;
        img(i+1,j) = img(i+1,j) + (errore*0.375);
        img(i,j+1) = img(i,j+1) + (errore*0.375);
        img(i+1,j+1) = img(i+1,j+1) + (errore*0.25);
    end
end
img = uint8(img);
%figure("Name","Immagine quantizzata più dithering");
%imshow(img, [0 255]);
end

