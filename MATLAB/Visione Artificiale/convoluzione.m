function padding=convoluzione(img)
[h, w, p]=size(img);
if(p~=1)
    img=rgb2gray(img);
end
kernel = fspecial('average');
padding=zeros(h,w);
padding(2:end-1, 2:end-1)=1;
index=find(padding);
lookUpTable=[-h-1,-h,-h+1,-1,0,1,h-1,h,h+1];
productLookUpTable=kernel(:)*(0:255);
for k=index
    tmp=0;
    for i=1:9
        tmp=tmp+productLookUpTable(i,img(k+lookUpTable(i))+1);
    end
    padding(k)=tmp;
end
padding=uint8(padding);

