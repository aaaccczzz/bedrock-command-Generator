#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int layer2,layer,count;	//定義基礎變數
    double start,increment;
    string name,name3,player,YorN,content,mod12;
	vector<string> facingname;
	vector<int> facingcount;
    cout << "輸入維度(1,2,3):";
    cin >> layer2;
    if (!(layer2 <= 3 && layer2 >= 1))
    {
        return 0;	//不符合規範時退出程式
    }
    cout << "輸入初始值:";
    cin >> start;
    vector<int> layer1(layer2);
    for (int i=0;i<layer2;i++){	//輸入xyz三個維度生成次數
        cout << "輸入第" << i+1 << "維度數量:";
        cin >> layer1[i];
    }
	cout << "輸入瞄準方式(1or2,rotate或facing):";	//瞄準方式(rotate跟facing)
    cin >> mod12;	
    cout << "輸入nx實體選擇器:";
    cin >> name;
	if (mod12 == "1"){
		if (layer2 == 3)	//維度是3多一個Y軸選項
		{
			cout << "輸入nx實體選擇器(y軸):";
			cin >> name3;
		}
	}
    cout << "輸入主實體目標選擇器:";
    cin >> player;
    
    const string strlist[4]={"^^^","^^","^",""};	//存放"^"內容，方便後續調用
    double defaultstart=start;
    cout << "是否需要facing偏離(Y/N):";
    cin >> YorN;
    if (YorN == "Y"){
		cout << "輸入偏移實體數量";	//偏移的實體數量
		cin >> count;
		int temp;
		string tempstr;
		for (int i=0;i<count;i++){
			cout << "輸入偏移實體選擇器:";
			cin >> tempstr;
			cout << "輸入偏移量:";
			cin >> temp;
			facingname.push_back(tempstr);
			facingcount.push_back(temp);
		}
    }
	cout << "輸入增量(倍數2或0.5):";		//每次乘以幾倍
	cin >> increment;
	cout << "輸入後續指令內容:";
	cin.get();
	getline(cin,content);
    cout << "execute as " << player << " at @s";
	const int list[3]={0,2,0};	//每個維度對應的"^"選項
    for (int j=0;j<layer2;j++)
    {
        start=defaultstart;
        for (int i=0;i<layer1[j];i++){
			if (mod12 == "1"){
				cout <<" rotated as "<< ((j == 2) ? name3 : name) << " positioned "<<strlist[list[j]]<<start<<strlist[3-list[j]];	//name3是3維實體名稱
			} else if (mod12 == "2"){
				cout <<" facing entity "<< name << " feet positioned "<<strlist[list[j]]<<start<<strlist[3-list[j]];
			}
			start *= increment; 	//建議*2
        }
    }
    if (YorN == "Y"){
		for (int i=0;i<facingname.size();i++){		//需要facing偏移
			cout << " facing entity " << facingname[i] << " feet positioned ^^^" << facingcount[i] << " rotated ~180 ~ positioned ^^^" << facingcount[i] ;
		}
    } else {
        cout << " ";    
    }
    cout << content;
    return 0;
}