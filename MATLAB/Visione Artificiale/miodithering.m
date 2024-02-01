function img = miodithering(img)
!img = rgb2gray(img);
img = single(img);
[h, w] = size(img);
for j = 1:h
    for i=1:w
       tmp = 255*(img(j,i)>127);
       err = img(j, i) - tmp;
       img(j, i) = tmp;
       if i<w && j<h
           img(j, i+1) = img(j, i+1)+0.375*err;
           img(j+1, i) = img(j+1, i)+0.375*err;
           img(j+1, i+1) = img(j+1, i+1)+0.25*err;
       elseif i<w
            img(j, i+1) = img(j, i+1)+1.0*err;
       elseif j<h
            img(j+1, i) = img(j+1, i)+1.0*err;
       end
    end
end