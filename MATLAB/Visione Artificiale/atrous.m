function atrous(img)
[heightImg, widthImg, sheets] = size(img);
if(sheets ~=1)
    img = rgb2gray(img);
end
img = double(img);
kernel = [[1,2,1];[2,4,2];[1,2,1]]*1/16;
[heightKernel, widthKernel, ~] = size(kernel);
numeroIterazioni = ceil(log2(min(heightImg,widthImg)));
iterazione = 2;
stackI = double(zeros([512,512,numeroIterazioni]));
stackI(:,:,1) = img;
stackW = double(zeros([512,512,numeroIterazioni]));
stackW(:,:,1) = img;
while((iterazione<=numeroIterazioni) | (heightKernel<=heightImg & widthKernel<=widthImg))
    %figure("Name","Kernel");
    %imshow(kernel,[]);
    %disp(kernel);
    stackI(:,:,iterazione) = conv2(stackI(:,:,iterazione-1),kernel,'same');
    stackW(:,:,iterazione) = stackI(:,:,iterazione-1) - stackI(:,:,iterazione);
    kernelTmp = zeros([heightKernel*2,widthKernel*2]);
    disp(kernelTmp);
    nonBuchi = find(kernel);
    for k = nonBuchi
        indiceI = mod(k-1,widthKernel)+1;
        indiceJ = floor((k-1)/widthKernel)+1;
        kernelTmp(indiceI*2,indiceJ*2) = kernel(indiceI,indiceJ);
    end
    kernel = kernelTmp;
    heightKernel = heightKernel*2;
    widthKernel = widthKernel*2;
    iterazione = iterazione+1;
end
disp(iterazione);
S = zeros([heightImg,widthImg]);
for i=2:iterazione-1
    %figure("Name","Convoluzione");
    %imshow(stackI(:,:,i),[]);
    %figure("Name","W");
    %imshow(stackW(:,:,i),[]);
    S = S + stackW(:,:,i);
end
S = S + stackI(:,:,iterazione-1);
figure("Name","Ricostruzione immagine");
imshow(S,[]);
end

