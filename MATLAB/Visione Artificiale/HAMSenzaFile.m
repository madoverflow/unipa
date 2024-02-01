function HAMSenzaFile(img)
disp('Indicizzo con HAM6');
[tavolozzaColori,buffers] = scritturaHAM6(img);
%figure("Name","Tavolozza colori");
%imagesc(tavolozzaColori);
disp('Decodifico HAM6');
out = letturaHAM6(tavolozzaColori,img,buffers);
%disp(sum(all(out == reshape([255 255 255], [1, 1, 3]), 3), 'all'));
figure("Name","Immagine true color");
imshow(img);
figure("Name","Immagine HAM6");
imshow(uint8(out));
% Carica l'immagine
img = out; % Sostituisci 'tua_immagine.jpg' con il percorso del tuo file immagine

% Reshape l'immagine in un vettore di pixel
pixels = reshape(img, [], 3);

% Calcola l'istogramma dei colori
histogram = histcounts2(pixels(:,1), pixels(:,2), 0:255, 0:255);

% Trova la posizione del massimo nell'istogramma
[~, ind] = max(histogram(:));

% Converti l'indice in coordinate (R, G)
[ind_R, ind_G] = ind2sub(size(histogram), ind);

% Recupera il colore RGB più frequente
colore_frequente = [ind_R - 1, ind_G - 1, 0];

disp(['Colore RGB più frequente: ', num2str(colore_frequente)]);

end

function [tavolozzaColori,buffers] = scritturaHAM6(img)
contatoreBuffer = 1;
[height, width, ~] = size(img);
img = single(img);
tavolozzaColori = round(hot(15)*255);
buffer32 = uint32(0);
tavolozzaColori = vertcat([img(1,1,1),img(1,1,2),img(1,1,3)],tavolozzaColori);
%setto il primo pixel nel buffer

%bit di controllo
buffer32 = bitset(buffer32,32,0);
buffer32 = bitset(buffer32,31,0);

%bit di dati: primo pixel indice pari ad 1
buffer32 = bitset(buffer32,30,0);
buffer32 = bitset(buffer32,29,0);
buffer32 = bitset(buffer32,28,0);
buffer32 = bitset(buffer32,27,0);

%fine

indiceBuffer = 26;

%HAM6 applicato alla prima riga (bordo)
for q=2:width
    pixelHAM6 = uint8(0);
    %controllo degli errori
    errore = abs(img(1,q,1)-tavolozzaColori(1,1))+abs(img(1,q,2)-tavolozzaColori(1,2))+abs(img(1,q,3)-tavolozzaColori(1,3));
    pixelHAM6 = bitset(pixelHAM6,6,0);
    pixelHAM6 = bitset(pixelHAM6,5,0);
    pixelHAM6 = bitset(pixelHAM6,4,0);
    pixelHAM6 = bitset(pixelHAM6,3,0);
    pixelHAM6 = bitset(pixelHAM6,2,0);
    pixelHAM6 = bitset(pixelHAM6,1,0);
    colorePixel = [tavolozzaColori(1,1),tavolozzaColori(1,2),tavolozzaColori(1,3)];
    %16 controlli: tavolozza colori
    for t=2:16
        nuovoErrore = abs(img(1,q,1)-tavolozzaColori(t,1))+abs(img(1,q,2)-tavolozzaColori(t,2))+abs(img(1,q,3)-tavolozzaColori(t,3));
        if nuovoErrore<errore
            errore = nuovoErrore;
            pixelHAM6 = bitset(pixelHAM6,6,0);
            pixelHAM6 = bitset(pixelHAM6,5,0);
            pixelHAM6 = bitset(pixelHAM6,4,bitget(t-1,4));
            pixelHAM6 = bitset(pixelHAM6,3,bitget(t-1,3));
            pixelHAM6 = bitset(pixelHAM6,2,bitget(t-1,2));
            pixelHAM6 = bitset(pixelHAM6,1,bitget(t-1,1));
            colorePixel = [tavolozzaColori(t,1),tavolozzaColori(t,2),tavolozzaColori(t,3)];
        end
    end
    %fine 16 controlli

    %3 controlli: R,G,B
    %controllo R
    nuovoErrore = abs(img(1,q,1)-img(1,q,1))+abs(img(1,q,2)-img(1,q-1,2))+abs(img(1,q,3)-img(1,q-1,3));
    if nuovoErrore < errore
        errore = nuovoErrore;
        colore = uint8(round((img(1,q,1)/255)*15));
        pixelHAM6 = bitset(pixelHAM6,6,1);
        pixelHAM6 = bitset(pixelHAM6,5,0);
        pixelHAM6 = bitset(pixelHAM6,4,bitget(colore,4));
        pixelHAM6 = bitset(pixelHAM6,3,bitget(colore,3));
        pixelHAM6 = bitset(pixelHAM6,2,bitget(colore,2));
        pixelHAM6 = bitset(pixelHAM6,1,bitget(colore,1));
        colorePixel = [uint8(round((single(colore)/15)*255)),img(1,q-1,2),img(1,q-1,3)];
    end
    %fine controllo R

    %controllo G
    nuovoErrore = abs(img(1,q,1)-img(1,q-1,1))+abs(img(1,q,2)-img(1,q,2))+abs(img(1,q,3)-img(1,q-1,3));
    if nuovoErrore < errore
        errore = nuovoErrore;
        colore = uint8(round((img(1,q,2)/255)*15));
        pixelHAM6 = bitset(pixelHAM6,6,1);
        pixelHAM6 = bitset(pixelHAM6,5,1);
        pixelHAM6 = bitset(pixelHAM6,4,bitget(colore,4));
        pixelHAM6 = bitset(pixelHAM6,3,bitget(colore,3));
        pixelHAM6 = bitset(pixelHAM6,2,bitget(colore,2));
        pixelHAM6 = bitset(pixelHAM6,1,bitget(colore,1));
        colorePixel = [img(1,q-1,1),uint8(round((single(colore)/15)*255)),img(1,q-1,3)];
    end
    %fine controllo G

    %controllo B
    nuovoErrore = abs(img(1,q,1)-img(1,q-1,1))+abs(img(1,q,2)-img(1,q-1,2))+abs(img(1,q,3)-img(1,q,3));
    if nuovoErrore < errore
        errore = nuovoErrore;
        colore = uint8(round((img(1,q,3)/255)*15));
        pixelHAM6 = bitset(pixelHAM6,6,0);
        pixelHAM6 = bitset(pixelHAM6,5,1);
        pixelHAM6 = bitset(pixelHAM6,4,bitget(colore,4));
        pixelHAM6 = bitset(pixelHAM6,3,bitget(colore,3));
        pixelHAM6 = bitset(pixelHAM6,2,bitget(colore,2));
        pixelHAM6 = bitset(pixelHAM6,1,bitget(colore,1));
        colorePixel = [img(1,q-1,1),img(1,q-1,2),uint8(round((single(colore)/15)*255))];
    end
    %fine controllo B
    %fine 3 controlli

    %scrittura su buffer
    for k=6:-1:1
        %disp("Scrivo sul buffer");
        %riempio il buffer
        buffer32 = bitset(buffer32,indiceBuffer,bitget(pixelHAM6,k));
        if indiceBuffer == 1
            %disp("Scrivo su file");
            %buffer pieno: scrittura su file + svuotamento
            buffers(contatoreBuffer) = buffer32;
            contatoreBuffer = contatoreBuffer + 1;
            %disp(buffer32);
            buffer32 = uint32(0);
            indiceBuffer = 32;
        else
            indiceBuffer = indiceBuffer-1;
        end
    end

    %aggiorno il pixel nell'immagine
    img(1,q,1)=colorePixel(1);
    img(1,q,2)=colorePixel(2);
    img(1,q,3)=colorePixel(3);
    %fine aggiornamento

    disp(num2str(bitget(pixelHAM6,6:-1:1)));
end
%fine HAM6 applicato alla prima riga

%HAM6 applicato alla parte restante dell'immagine
for j=1:width
    for i=2:height
        pixelHAM6 = uint8(0);
        %controllo degli errori
        errore = abs(img(i,j,1)-tavolozzaColori(1,1))+abs(img(i,j,2)-tavolozzaColori(1,2))+abs(img(i,j,3)-tavolozzaColori(1,3));
        pixelHAM6 = bitset(pixelHAM6,6,0);
        pixelHAM6 = bitset(pixelHAM6,5,0);
        pixelHAM6 = bitset(pixelHAM6,4,0);
        pixelHAM6 = bitset(pixelHAM6,3,0);
        pixelHAM6 = bitset(pixelHAM6,2,0);
        pixelHAM6 = bitset(pixelHAM6,1,0);
        colorePixel = [tavolozzaColori(1,1),tavolozzaColori(1,2),tavolozzaColori(1,3)];
        %16 controlli: tavolozza colori
        for t=2:16
            nuovoErrore = abs(img(i,j,1)-tavolozzaColori(t,1))+abs(img(i,j,2)-tavolozzaColori(t,2))+abs(img(i,j,3)-tavolozzaColori(t,3));
            if nuovoErrore<errore
                errore = nuovoErrore;
                pixelHAM6 = bitset(pixelHAM6,6,0);
                pixelHAM6 = bitset(pixelHAM6,5,0);
                pixelHAM6 = bitset(pixelHAM6,4,bitget(t-1,4));
                pixelHAM6 = bitset(pixelHAM6,3,bitget(t-1,3));
                pixelHAM6 = bitset(pixelHAM6,2,bitget(t-1,2));
                pixelHAM6 = bitset(pixelHAM6,1,bitget(t-1,1));
                colorePixel = [tavolozzaColori(t,1),tavolozzaColori(t,2),tavolozzaColori(t,3)];
            end
        end
        %fine 16 controlli

        %3 controlli: R, G,B
        %controllo R
        nuovoErrore = abs(img(i,j,1)-img(i,j,1))+abs(img(i,j,2)-img(i-1,j,2))+abs(img(i,j,3)-img(i-1,j,3));
        if nuovoErrore < errore
            errore = nuovoErrore;
            colore = uint8(round((img(i,j,1)/255)*15));
            pixelHAM6 = bitset(pixelHAM6,6,1);
            pixelHAM6 = bitset(pixelHAM6,5,0);
            pixelHAM6 = bitset(pixelHAM6,4,bitget(colore,4));
            pixelHAM6 = bitset(pixelHAM6,3,bitget(colore,3));
            pixelHAM6 = bitset(pixelHAM6,2,bitget(colore,2));
            pixelHAM6 = bitset(pixelHAM6,1,bitget(colore,1));
            colorePixel = [uint8(round((single(colore)/15)*255)),img(i-1,j,2),img(i-1,j,3)];
        end
        %fine controllo R

        %controllo G
        nuovoErrore = abs(img(i,j,1)-img(i-1,j,1))+abs(img(i,j,2)-img(i,j,2))+abs(img(i,j,3)-img(i-1,j,3));
        if nuovoErrore < errore
            errore = nuovoErrore;
            colore = uint8(round((img(i,j,2)/255)*15));
            pixelHAM6 = bitset(pixelHAM6,6,1);
            pixelHAM6 = bitset(pixelHAM6,5,1);
            pixelHAM6 = bitset(pixelHAM6,4,bitget(colore,4));
            pixelHAM6 = bitset(pixelHAM6,3,bitget(colore,3));
            pixelHAM6 = bitset(pixelHAM6,2,bitget(colore,2));
            pixelHAM6 = bitset(pixelHAM6,1,bitget(colore,1));
            colorePixel = [img(i-1,j,1),uint8(round((single(colore)/15)*255)),img(i-1,j,3)];
        end
        %fine controllo G

        %controllo B
        nuovoErrore = abs(img(i,j,1)-img(i-1,j,1))+abs(img(i,j,2)-img(i-1,j,2))+abs(img(i,j,3)-img(i,j,3));
        if nuovoErrore < errore
            errore = nuovoErrore;
            colore = uint8(round((img(i,j,3)/255)*15));
            pixelHAM6 = bitset(pixelHAM6,6,0);
            pixelHAM6 = bitset(pixelHAM6,5,1);
            pixelHAM6 = bitset(pixelHAM6,4,bitget(colore,4));
            pixelHAM6 = bitset(pixelHAM6,3,bitget(colore,3));
            pixelHAM6 = bitset(pixelHAM6,2,bitget(colore,2));
            pixelHAM6 = bitset(pixelHAM6,1,bitget(colore,1));
            colorePixel = [img(i-1,j,1),img(i-1,j,2),uint8(round((single(colore)/15)*255))];
        end
        %fine controllo B
        %fine 3 controlli

        %scrittura su buffer
        for k=6:-1:1
            %disp("Scrivo sul buffer");
            %riempio il buffer
            buffer32 = bitset(buffer32,indiceBuffer,bitget(pixelHAM6,k));
            if indiceBuffer == 1
                %disp("Scrivo su file");
                %buffer pieno: scrittura su file + svuotamento
                buffers(contatoreBuffer) = buffer32;
                contatoreBuffer = contatoreBuffer +1;
                buffer32 = uint32(0);
                indiceBuffer = 32;
            else
                indiceBuffer = indiceBuffer-1;
            end
        end
        %aggiorno il pixel nell'immagine
        img(i,j,1)=colorePixel(1);
        img(i,j,2)=colorePixel(2);
        img(i,j,3)=colorePixel(3);
        %fine aggiornamento
    end
end
%fine HAM6 applicato alla parte restante dell'immagine

%controllo se il buffer ha ancora delle informazioni ed in caso lo scrivo
%su file
if buffer32>0
    buffers(contatoreBuffer) = buffer32;
end
%fine controllo
figure("Name","Ham6");
imshow(img);
end

function out = letturaHAM6(tavolozzaColori,img,buffers)
contatoreBuffer = 1;
[height, width, sheets] = size(img);
out = zeros(height,width,sheets);

%leggo il primo pixel
buffer32 = buffers(contatoreBuffer);
contatoreBuffer = contatoreBuffer + 1;
out(1,1,1) = tavolozzaColori(1,1);
out(1,1,2) = tavolozzaColori(1,2);
out(1,1,3) = tavolozzaColori(1,3);
indiceBuffer = 26;
%fine lettura

%leggo la prima riga
for q=2:width
    pixelHAM6 = uint8(0);
    for k=6:-1:1
        %leggo il buffer
        pixelHAM6 = bitset(pixelHAM6,k,bitget(buffer32,indiceBuffer));
        if indiceBuffer == 1
            %buffer vuoto. Carico il buffer successivo se disponibile
            if contatoreBuffer > length(buffers)
                disp("Non sono disponibili più buffer");
                return;
            end
            buffer32 = buffers(contatoreBuffer);
            contatoreBuffer = contatoreBuffer + 1;
            indiceBuffer = 32;
        else
            indiceBuffer = indiceBuffer - 1;
        end
    end
    disp(num2str(bitget(pixelHAM6,6:-1:1)));

    %lettura dei bit di controllo
    bitDiControllo = bin2dec(num2str(bitget(pixelHAM6,6:-1:5)));
    switch bitDiControllo
        case 0
            %lettura dalla tavolozza colori
            indiceTavolozzaColori = bin2dec(num2str(bitget(pixelHAM6,4:-1:1)))+1;
            out(1,q,1) = tavolozzaColori(indiceTavolozzaColori,1);
            out(1,q,2) = tavolozzaColori(indiceTavolozzaColori,2);
            out(1,q,3) = tavolozzaColori(indiceTavolozzaColori,3);
        case 1
            %caso B
            sfumaturaDiBlu = round((bin2dec(num2str(bitget(pixelHAM6,4:-1:1)))/15)*255);
            out(1,q,1) = out(1,q-1,1);
            out(1,q,2) = out(1,q-1,2);
            out(1,q,3) = sfumaturaDiBlu;
        case 2
            %caso R
            sfumaturaDiRosso = round((bin2dec(num2str(bitget(pixelHAM6,4:-1:1)))/15)*255);
            out(1,q,1) = sfumaturaDiRosso;
            out(1,q,2) = out(1,q-1,2);
            out(1,q,3) = out(1,q-1,3);
        case 3
            %caso G
            sfumaturaDiVerde = round((bin2dec(num2str(bitget(pixelHAM6,4:-1:1)))/15)*255);
            out(1,q,1) = out(1,q-1,1);
            out(1,q,2) = sfumaturaDiVerde;
            out(1,q,3) = out(1,q-1,3);
    end
    %fine lettura dei bit di controllo
end
%fine lettura prima riga

%leggo la parte restante dell'immagine
for j=1:width
    for i=2:height
        pixelHAM6 = uint8(0);
        for k=6:-1:1
            %leggo il buffer
            pixelHAM6 = bitset(pixelHAM6,k,bitget(buffer32,indiceBuffer));
            if indiceBuffer == 1
                %buffer vuoto. Carico il buffer successivo se disponibile
                if contatoreBuffer > length(buffers)
                    disp("Non sono disponibili più buffer");
                    return;
                end
                buffer32 = buffers(contatoreBuffer);
                contatoreBuffer = contatoreBuffer + 1;
                indiceBuffer = 32;
            else
                indiceBuffer = indiceBuffer - 1;
            end
        end

        %lettura dei bit di controllo
        bitDiControllo = bin2dec(num2str(bitget(pixelHAM6,6:-1:5)));
        switch bitDiControllo
            case 0
                %lettura dalla tavolozza colori
                indiceTavolozzaColori = bin2dec(num2str(bitget(pixelHAM6,4:-1:1)))+1;
                out(i,j,1) = tavolozzaColori(indiceTavolozzaColori,1);
                out(i,j,2) = tavolozzaColori(indiceTavolozzaColori,2);
                out(i,j,3) = tavolozzaColori(indiceTavolozzaColori,3);
            case 1
                %caso B
                sfumaturaDiBlu = round((bin2dec(num2str(bitget(pixelHAM6,4:-1:1)))/15)*255);
                out(i,j,1) = out(i-1,j,1);
                out(i,j,2) = out(i-1,j,2);
                out(i,j,3) = sfumaturaDiBlu;
            case 2
                %caso R
                sfumaturaDiRosso = round((bin2dec(num2str(bitget(pixelHAM6,4:-1:1)))/15)*255);
                out(i,j,1) = sfumaturaDiRosso;
                out(i,j,2) = out(i-1,j,2);
                out(i,j,3) = out(i-1,j,3);
            case 3
                %caso G
                sfumaturaDiVerde = round((bin2dec(num2str(bitget(pixelHAM6,4:-1:1)))/15)*255);
                out(i,j,1) = out(i-1,j,1);
                out(i,j,2) = sfumaturaDiVerde;
                out(i,j,3) = out(i-1,j,3);
        end
        %fine lettura dei bit di controllo
    end
end
%fine lettura parte restante immagine

end

