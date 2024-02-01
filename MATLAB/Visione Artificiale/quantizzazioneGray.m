function img = quantizzazioneGray(img,numeroColori)
[~,~,sheets] = size(img);
if(sheets~=1)
    img = double(rgb2gray(img));
end
i=0;
minimo = min(img(:));
massimo = max(img(:));
passo = (massimo-minimo)/numeroColori;
%faccio tutte le operazioni fino a 2 passi prima poiché i semi intervalli
%devono essere limitati in questo modo [estremoInferiore,estremoSuperiore)
%e il minimo e massimo degli elementi dell'immagini sono elementi stessi
%dell'immagine quindi l'intervallo di tutti gli elementi dell'immagine
%è limitato in questo modo [minimo,massimo]. Con questo ciclo, prendo in
%considerazione il minimo ed escludo l'estremo superiore cosicché possa
%includerlo negli altri semi intervalli come estremo inferiore
for i=minimo:passo:massimo-(passo+passo)
    estremoInferiore = round(i);
    estremoSuperiore = round(i+passo);
    posizioni = find(img>=estremoInferiore & img<estremoSuperiore);
    media = mean(img(posizioni));
    img(posizioni) = round(media);
end
%per prendere includere il massimo in un semi intervallo, mi calcolo
%l'ultimo semi intervallo a parte (per questo mi ero fermato a 2 passi
%precedenti). A questo punto devo sia includere l'estremo inferiore che
%l'estremo superiore, il quale sarà il massimo. Dunque,
%[estremoInferiore (estremo superiore del semi intervallo precedente),
%massimo]
i = i+passo;
estremoInferiore = round(i);
estremoSuperiore = round(i+passo);
posizioni = find(img>=estremoInferiore & img<=estremoSuperiore);
media = mean(img(posizioni));
img(posizioni) = round(media);
img = uint8(img);
%figure("Name","Immagine quantizzata");
%imshow(img, [0, 255]);
end

