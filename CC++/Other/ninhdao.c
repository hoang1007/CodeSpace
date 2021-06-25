#include <stdio.h>
#include <string.h>

typedef struct SinhVien
{
    int msv;
    char ho[10];
    char ten[10];
    int namsinh;
} SV;

int kiemTraTen(char ten[])
{
    for (int i = 0; ten[i] != '\0'; i++)
        if ( (ten[i] >= 'a' && ten[i] <= 'z') || (ten[i] >= 'A' && ten[i] <= 'Z'))
            continue;
        else return 0;
    return 1;
}

SV nhap()
{
    SV sv;

    printf("MSSV: ");   
    while (scanf("%d", &sv.msv) == 0)
    {
        fflush(stdin);
        printf("MSSV khong hop le. Vui long nhap lai: ");
    }
    
    int hople = 0;
    
    printf("Ho cua sinh vien: ");
    while (1)
    {
        scanf("%s", sv.ho);
        if (kiemTraTen(sv.ho) == 0)
            printf("Ho khong hop le. Vui long nhap lai: ");
        else break;
    }

    printf("Ten cua sinh vien: ");
    while (1)
    {
        scanf("%s", sv.ten);
        if (kiemTraTen(sv.ten) == 0)
            printf("Ten khong hop le. Vui long nhap lai: ");
        else break;
    }

    printf("Nam sinh: ");
    while (scanf("%d", &sv.namsinh) == 0)
    {
        fflush(stdin);
        printf("Nam sinh khong hop le. Vui long nhap lai: ");
    }
    
    printf("Thanh cong!\n");
    return sv;
}

void xuat(SV sv)
{
    printf("%d\t%s\t%s\t%d\n", sv.msv, sv.ho, sv.ten, sv.namsinh);
}

void swap(SV sinhvien[], int i, int j)
{
    SV temp = sinhvien[i];
    sinhvien[i] = sinhvien[j];
    sinhvien[j] = temp;
}

void sapXepTheoTen(SV sinhvien[], int soSV)
{
    for (int i = 0; i < soSV - 1; i++)
        for (int j = i + 1; j < soSV; j++)
            if ( strcmp(sinhvien[i].ten, sinhvien[j].ten) > 0)
                swap(sinhvien, i, j);
    
    printf("MSSV\tHO\tTEN\tNAM SINH\n");

    for (int i = 0; i < soSV; i++)
        xuat(sinhvien[i]);
}

void locTheoNam(SV sinhvien[], int soSV, int nam)
{
    printf("MSSV\tHO\tTEN\tNAM SINH\n");

    for (int i = 0; i < soSV; i++)
        if (sinhvien[i].namsinh < nam)
            xuat(sinhvien[i]);
}

void locTheoTuoi(SV sinhvien[], int soSV)
{
    SV copy[soSV];
    for (int i = 0; i < soSV; i++)
        copy[i] = sinhvien[i];
    
    for (int i = 0; i < soSV - 1; i++)
        for (int j = i + 1; j < soSV; j++)
            if (copy[i].namsinh < copy[j].namsinh)
                swap(copy, i, j);

    printf("MSSV\tHO\tTEN\tNAM SINH\n");

    for (int i = 0; i < soSV; i++)
        xuat(copy[i]);
}

int main()
{
    int soSV;
    printf("Nhap so sinh vien: "); 
    while (1)
    {
        if (scanf("%d", &soSV) == 0)
            printf("So vinh vien khong hop le. Nhap lai: ");
        else if (soSV > 50)
            printf("So sinh vien qua lon. Nhap lai: ");
        else break;
    }
    
    SV sinhvien[soSV];

    for (int i = 0; i < soSV; i++)
        sinhvien[i] = nhap();
    
    printf("\nNhan 1 de tim cac sinh vien sinh truoc nam\n");
    printf("Nhan 2 de dua ra cac sinh vien nho tuoi nhat\n");
    printf("Nhan 3 de sap xep danh sach sinh vien theo thu tu cua ten\n");
    printf("Nhan 0 de thoat\n");

    int keycode = -1;
    while (scanf("%d", &keycode) && keycode != 0)
    {
        switch (keycode)
        {
            case 1:
            {
                printf("Nhap nam muon loc: ");
                int nam;
                while (scanf("%d", &nam) == 0)
                    printf("Nam khong hop le. Nhap lai: ");
                
                locTheoNam(sinhvien, soSV, nam);
                break;
            }
            case 2:
                locTheoTuoi(sinhvien, soSV);
                break;
            case 3:
                sapXepTheoTen(sinhvien, soSV);
                break;
            default: 
                break;
        }
    }
}