function istogrammaLuminanzaSenzaOutliers(img)
[frequencies, extremes] = imhist(img,256);
mascheraBinaria = zeros(size(frequencies));
%disp(std(frequencies));
%disp(mean(frequencies));
media = mean(frequencies);
standardDeviation = std(frequencies); 
figure("Name","Istogramma con outliers");
xlabel("Frequenze");
ylabel("Scala di grigio");
bar(extremes,frequencies);
for i=1:length(frequencies)
    if abs(frequencies(i)-media)>2*standardDeviation
        %disp("Frequenza");
        %disp(frequencies(i));
        %disp("Posizione");
        %disp(i);
        mascheraBinaria(i)=1;
    end
end
frequencies(find(mascheraBinaria))=[];
extremes(find(mascheraBinaria))=[];
figure("Name","Istogramma senza outliers");
xlabel("Frequenze");
ylabel("Scala di grigio");
bar(extremes,frequencies);
figure("Name","Maschera binaria");
imshow(mascheraBinaria,[]);
end

