#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int layer2,layer,facingcount;
    double start;
    string name,player,YorN,facingname,content;
    cout << "輸入維度(1,2,3):";
    cin >> layer2;
    if (!(layer2 <= 3 && layer2 >= 1))
    {
        return 1;
    }
    cout << "輸入初始值:";
    cin >> start;
    vector<int> layer1(layer2);
    for (int i=0;i<layer2;i++){
        cout << "輸入第" << i+1 << "維度數量:";
        cin >> layer1[i];
    }
    cout << "輸入nx實體名稱:";
    cin >> name;
    cout << "輸入主實體目標選擇器:";
    cin >> player;
    
    const string strlist[4]={"^^^","^^","^",""};
    double defaultstart=start;
    cout << "是否需要facing偏離(Y/N):";
    cin >> YorN;
    if (YorN == "Y"){
        cout << "輸入偏移實體選擇器:";
        cin >> facingname;
		cout << "輸入偏移量:";
		cin >> facingcount;
    }
	cout << "輸入後續指令內容:";
	cin.get();
	getline(cin,content);
    cout << "execute as " << player << " at @s";
	const int list[3]={0,2,1};
    for (int j=0;j<layer2;j++)
    {
        start=defaultstart;
        for (int i=0;i<layer1[j];i++){
            cout <<" rotated as @e[name=\""<< name <<"\"] positioned "<<strlist[list[j]]<<start<<strlist[3-list[j]];
			start *= 2;
        }
    }
    if (YorN == "Y"){
        cout << " facing entity " << facingname << " feet positioned ^^^" << facingcount << " " ;
    } else {
        cout << " ";    
    }
    cout << content;
    return 0;
}