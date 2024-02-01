function out=equalizzatore(img)
s=prod(size(img))/255;
lut=uint8(round(cumsum(imhist(uint8(img),256))/s)); 
out=lut(img+1);