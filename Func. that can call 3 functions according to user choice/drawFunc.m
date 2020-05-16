function[r]= drawFunc(b)
b = input('Enter Func argument 1 for Batman , 2 for Traffic , 3 for Calculator :')

    flag =1;
    while (flag ==1 )
        switch(b)
            case 1
                drawBat();
            case 2
                drawTraffic();
            case 3
                x=input('Enter x:');
                y=input('Enter y:');
                o=input('Enter Operation:','s');
                calculator(x,y,o);
        end
        flag = input('Enter 0 if you want to stop or 1 to continue');
    end
end


