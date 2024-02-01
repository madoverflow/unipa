function istogrammaLuminanza(img)
img = rgb2gray(img);
[count, locations] = imhist(img,256);
figure("Name","Istogramma luminanza");
bar(locations,count);
xlabel("F");
ylabel("L");
end