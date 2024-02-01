function threshold = otsu(img)
[~, ~, sheets] = size(img);
if(sheets ~= 1)
    img = double(rgb2gray(img));
end
%prima divisione otsu
count = 1;
vec(count) = round((min(img(:)) + max(img(:)))*0.5);
threshold = 0;
while(1)
    disp("Inizio a fare")
    disp(vec(count))
    bm = img>vec(count);
    valoriMaggioriThreshold = img(bm==1);
    valoriMinoriThreshold = img(bm==0);
    mediaValoriMaggioriThreshold = mean(valoriMaggioriThreshold);
    mediaValoriMinoriThreshold = mean(valoriMinoriThreshold);
    threshold = round(mean([mediaValoriMaggioriThreshold,mediaValoriMinoriThreshold]));
    disp("Media determinata")
    disp(threshold)
    if(ismember(threshold,vec))
        break;
    end
    count = count+1;
    vec(count) = threshold;
end
imshow(img>=threshold, []);