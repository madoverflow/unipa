function f(img)
[height,width,sheets] = size(img);
base = 256;
%errori = 200;
if sheets~=1
    img = rgb2gray(img);
end
[frequencies, extremes] = imhist(img,base);
figure("Name","Istogramma senza equalizzazione");
xlabel("Frequenze");
ylabel("Pixel");
bar(extremes,frequencies);
area = height*width;
altezza = area/base;
media = round(mean(frequencies(frequencies<altezza)));
errori = frequencies(frequencies>altezza)-media;
frequencies(frequencies>altezza) = media;
for i=1:length(errori)
    frazioneErrore = errori(i)/256;
    frequencies = frequencies+frazioneErrore;
end
frequencies = frequencies-min(frequencies(:));
frequencies = round((frequencies/max(frequencies(:)))*255);
disp(frequencies(127));
immagine = frequencies(img+1);
figure("Name","Istogramma con equalizzazione");
xlabel("Frequenze");
ylabel("Pixel");
bar(extremes,frequencies);
end