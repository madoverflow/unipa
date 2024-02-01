function convoluzioneGenerica(img,kernel)
    [height,width,sheets] = size(img);
    [heightKernel,widthKernel,~] = size(kernel);
    if heightKernel>height || widthKernel>width
        disp("Kernel più grande dell'immagine. Convoluzione fallita");
        return;
    end
    if sheets~=1
        img = single(rgb2gray(img));
    end
    lutProdotti = kernel(:)*(0:255);
    limiteSinistroRiga = floor((heightKernel-1)/2);
    limiteDestroRiga = floor(heightKernel/2);
    limiteSinistroColonna = floor((widthKernel-1)/2);
    limiteDestroColonna = floor(widthKernel/2);
    out = zeros(height,width);
    out((1+limiteSinistroRiga):(end-limiteDestroRiga),(1+limiteSinistroColonna):(end-limiteDestroColonna)) = 1;
    lutK = lutKernel(kernel,height);
    for posizione=find(out)
        tmp = 0;
        for i=1:heightKernel*widthKernel
            tmp = tmp + lutProdotti(i,img(posizione+lutK(i))+1);
        end
        out(posizione) = tmp;
    end
    out = uint8(round(out));
    figure("Name","Immagine pre convoluzione");
    imshow(img,[0 255]);
    figure("Name","Immagine post convoluzione");
    imshow(out,[0 255]);
end

function LUT = lutKernel(kernel,heightImg)
    [heightKernel,widthKernel,~] = size(kernel);
    limiteSinistroH = floor((widthKernel-1)/2);
    limiteDestroH = floor((widthKernel)/2);
    lutH = heightImg*horzcat(-limiteSinistroH:1:0,1:limiteDestroH);
    limiteSinistroN = floor((heightKernel-1)/2);
    limiteDestroN = floor((heightKernel)/2);
    lutN = vertcat((-limiteSinistroN:1:0)',(1:limiteDestroN)');
    LUT = bsxfun(@plus,lutN,lutH);
    LUT = LUT(:);
end