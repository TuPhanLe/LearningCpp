
/*******************************************************************************
************ Bài tập lập trình C++ cơ bản - Bài 13.1 ****************************
********************** vunguyencoder.com **************************************

Trong 1 xóm có 4 nhà đặt cạnh nhau theo thứ tự: 
|Vu|---|Ozawa|---|Ngoc Trinh|---|Son Tun MTP|
- Biết mỗi người sẽ đều có nhà hàng xóm bên trái và bên phải 
(trừ người đầu tiên và người cuối cùng )

Cho struct Person gồm trường tên và thông tin của 2 hàng xóm 
1 - Lập trình để tạo liên kết cho 4 người trên 
2 - Viết hàm show_neighbourhood có chức năng in ra tên 
3 - Viết hàm kiểm tra 2 nhà có phải hàng xóm với nhau hay ko 
4 - Viết hàm kiểm tra xem người đó là ở đầu xóm, cuối xóm hãy giữa xóm 
Người đầu xóm là người ko có hàng xóm bên trái 
Người cuối xóm là người ko có hàng xóm bên phải 
Người giữa xóm là người có cả hàng xóm bên trái và phải 
Người ko ở trong xóm là người ko có hàng xóm bên trái và phải 

* ******************************************************************************/

#include <iostream>

using namespace std;

struct Person
{
    Person(std::string fn)
    {
        fullname = fn;
    }
    string fullname;
    Person* left_neighbourhood = NULL;
    Person* right_neighbourhood = NULL;
};

void print_neighbourhood(Person *person)
{
    // Noi dung can hoan thanh
    
    if(person->left_neighbourhood != NULL){
        std::cout<<"Hang xom ben trai cua " << person->fullname << " la";
        std::cout<<(person->left_neighbourhood->fullname)<<"\n";
    }
    if(person->right_neighbourhood != NULL){
        std::cout<<"Hang xom ben phai cua " << person->fullname << " la ";
        std::cout<<(person->right_neighbourhood->fullname)<<"\n";
    }    
    
}

void check_neighbourhooh(Person* person1, Person* person2)
{
    // Noi dung can hoan thanh
    if((person1->left_neighbourhood== person2)|| 
        (person1 == person2->left_neighbourhood))
    {
        std::cout<<person1->fullname << " la hang xom cua "<<person2->fullname;
    }
    else std::cout << person1->fullname << " khong phai la hang xom cua "<<person2->fullname;
    std::cout << "\n";
}

string check_position(Person* person)
{
    if( person->left_neighbourhood != NULL || person->right_neighbourhood != NULL ){
        if(person->left_neighbourhood == NULL){
            return "Dau xom";
        }
        else if(person->right_neighbourhood == NULL){
        return "Cuoi xom";
        }
        else return "Giua xom";
    }
    if(person->left_neighbourhood == NULL || person->right_neighbourhood == NULL) return "Khong o trong xom";
}

int main()
{
    Person* vu = new Person("Vu");
    Person* ozawa = new Person("Maria Ozawa");
    Person* ngoc_trinh = new Person("Ngoc Trinh");
    Person* son_tung_mtp = new Person("Son Tung MTP");
    Person* tokuda = new Person("Tokuda");
    
    {
       // Noi dung cau 1 
       vu->right_neighbourhood = ozawa;
       ozawa->right_neighbourhood = ngoc_trinh;
       ngoc_trinh->right_neighbourhood = son_tung_mtp;
       son_tung_mtp->left_neighbourhood = ngoc_trinh;
       ozawa->left_neighbourhood = vu;
       ngoc_trinh->left_neighbourhood = ozawa;
    //    son_tung_mtp->right_neighbourhood = tokuda;
    }
    
    {
        std::cout << "Test 1 - In thong tin hang xom: \n";
        cout << "\t"; print_neighbourhood(vu);
        cout << "\t"; print_neighbourhood(ngoc_trinh);
    }
    
    {
        std::cout << "Test 2 - Kiem tra hang xom: \n";
        cout << "\t"; check_neighbourhooh(vu, ozawa);
        cout << "\t"; check_neighbourhooh(vu, ngoc_trinh);
    }
    
    {
        std::cout << "Test 3 - Kiem tra vi tri: \n";
        cout << "\tVi tri cua " << vu->fullname << " la: " << check_position(vu) << "\n";
        cout << "\tVi tri cua " << ngoc_trinh->fullname << " la: " << check_position(ngoc_trinh) << "\n";
        cout << "\tVi tri cua " << son_tung_mtp->fullname << " la: " << check_position(son_tung_mtp) << "\n";
        cout << "\tVi tri cua " << tokuda->fullname << " la: " << check_position(tokuda) << "\n";
    }
}






