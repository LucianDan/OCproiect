clc;
clear;
delete(instrfind({'Port'},{'COM3'}));
port = serial('COM3','BaudRate',19200);
fopen(port);
x = 0;
y10= zeros(1,100);
y20 = zeros(1,100);
y1 = typecast( y10 , 'single');
y2 = typecast( y20 , 'single');
while(x < 100)
    x = x+1;
    [y1(x) y2(x)] = fscanf(port,'%f f'); 
    subplot(2,1,1)
    plot(y1,'LineWidth',2)
   
    subplot(2,1,2)
    plot(y2,'LineWidth',2)
    pause(1);
end
fclose(port);
delete(port);