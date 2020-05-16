clc;   
clearvars;
close all
workspace;  
format long g;
format compact;
rectangle(...
	'Position', [0 0 2 4], ...
	'Curvature', 0.2, ...
	'FaceColor', 'k')
axis equal
hold on;
darkGray = [0.2, 0.2, 0.2];
green = [0, 132, 80] / 255;
yellow = [239, 183, 0] / 255;
red = [184, 29, 19] / 255;
while 1
pos = [0.5 2.75 1 1]; 
rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', darkGray)
pos = [0.5 1.5 1 1]; 
rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', darkGray)
pos = [0.5 0.25 1 1]; 
rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', darkGray)
i= 1;
for i = 1 : 3  
    if i == 1
        pos = [0.5 2.75 1 1]; 
        rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', red)
        pause(1);
        rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', darkGray)
    elseif i == 2
        pos = [0.5 1.5 1 1]; 
        rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', yellow)
        pause(1);
        rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', darkGray)
    elseif i == 3
        pos = [0.5 0.25 1 1]; 
        rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', green)
        pause(1);
        rectangle('Position', pos, 'Curvature',[1 1], 'FaceColor', darkGray)
    end
end
i=1;
title('Traffic Lights', 'FontSize', 24);
%xlim([-0.5, 2.5]);
%ylim([-0.5, 4.5]);
end

