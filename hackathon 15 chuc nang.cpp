#include <stdio.h>

int main() {
    int arr[100];
    int size = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang (arr[0]=..., arr[1]=...)\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu 2 (Khong sap xep)\n");
        printf("6. Tim gia tri nho thu 2 (Khong sap xep)\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (sap xep chen)\n");
        printf("10. Sap xep mang giam dan (sap xep chen)\n");
        printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Dao nguoc mang\n");
        printf("15. Thoat\n");
        printf("Moi ban nhap lua chon : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
            	// Nhap so luong va gia tri cho cac phan tu
                printf("Nhap so luong phan tu (toi da 100): ");
                scanf("%d", &size);
                if (size <= 0 || size > 100) {
                    printf("So luong khong hop le!\n");
                    size = 0;
                } else {
                    for (int i = 0; i < size; i++) {
                        printf("Nhap gia tri cho arr[%d]: ", i);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            }
            case 2: {
            	// In mang (arr[0]=..., arr[1]=...)
                if (size == 0) {
                    printf("Mang dang khong co phan tu!\n");
                } else {
                    printf("Mang hien tai: ");
                    for (int i = 0; i < size; i++) {
                        printf("arr[%d]=%d ", i, arr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
            	// Dem so luong so hoan hao
                int count = 0;
                for (int i = 0; i < size; i++) {
                    int sum = 0;
                    for (int j = 1; j <= arr[i] / 2; j++) {
                        if (arr[i] % j == 0) sum += j;
                    }
                    if (sum == arr[i]) count++;
                }
                printf("So luong so hoan hao: %d\n", count);
                break;
            }
            case 4: {
            	// Dem so luong so nguyen to
                int count = 0;
                for (int i = 0; i < size; i++) {
                    int Prime = arr[i] > 1;
                    for (int j = 2; j * j <= arr[i] && Prime; j++) {
                        if (arr[i] % j == 0) Prime = 0;
                    }
                    if (Prime) count++;
                }
                printf("So luong so nguyen to: %d\n", count);
                break;
            }
            case 5: {
            	//Tim gia tri lon thu 2 (Khong sap xep)
                if (size < 2) {
                    printf("Mang phai tu 2 phan tu tro len!\n");
                } else {
                    int max1 = arr[0];
					int max2 = -2147483647;
                    for (int i = 1; i < size; i++) {
                        if (arr[i] > max1) {
                            max2 = max1;
                            max1 = arr[i];
                        } else if (arr[i] > max2 && arr[i] < max1) {
                            max2 = arr[i];
                        }
                    }
                    printf("Gia tri lon thu hai: %d\n", max2);
                }
                break;
            }
            case 6: {
            	//Tim gia tri nho thu 2 (Khong sap xep)
                if (size < 2) {
                    printf("Mang phai tu 2 phan tu tro len\n");
                } else {
                    int min1 = arr[0], min2 = 2147483647;
                    for (int i = 1; i < size; i++) {
                        if (arr[i] < min1) {
                            min2 = min1;
                            min1 = arr[i];
                        } else if (arr[i] < min2 && arr[i] > min1) {
                            min2 = arr[i];
                        }
                    }
                    printf("Gia tri nho thu hai la: %d\n", min2);
                }
                break;
            }
            case 7: {
            	//Them phan tu tai vi tri
                if (size >= 100) {
                    printf("Mang da day khong the them phan tu\n");
                } else {
                    int value, vitri;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri can them (0-%d): ", size);
                    scanf("%d", &vitri);
                    if (vitri < 0 || vitri > size) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = size; i > vitri; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[vitri] = value;
                        size++;
                        printf("Da them %d vao vi tri %d.\n", value,vitri);
                    }
                }
                break;
            }
            case 8: {
            	//Xoa phan tu tai vi tri
                if (size == 0) {
                    printf("Mang dang khong co phan tu\n");
                } else {
                    int vitri;
                    printf("Nhap vi tri can xoa (0-%d): ", size - 1);
                    scanf("%d", &vitri);
                    if (vitri < 0 || vitri >= size) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = vitri; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Da xoa phan tu tai vi tri %d.\n", vitri);
                    }
                }
                break;
            }
            case 9: {
            	//Sap xep mang tang dan (sap xep chen)
                for (int i = 1; i < size; i++) {
                    int key = arr[i], j = i - 1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang da sap xep tang dan.\n");
                break;
            }
            case 10: {
            	//Sap xep mang giam dan (sap xep chen)
                for (int i = 1; i < size; i++) {
                    int key = arr[i], j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang da sap xep giam dan.\n");
                break;
            }
            case 11: {
            	//Tim kiem phan tu (Tim kiem nhi phan)
                int key;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &key);
                int left = 0, right = size - 1;
                int found = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[mid] == key) {
                        printf("Tim thay %d tai vi tri %d.\n", key, mid);
                        found = 1;
                        break;
                    }
                    if (arr[mid] < key) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("%d khong ton tai trong mang.\n", key);
                }
                break;
            }
            case 12: {
            	// Xoa phan tu trung lap va in phan tu doc nhat
            	 for (int i = 0; i < size; i++) {
        			for (int j = i + 1; j < size;) {
           				 if (arr[i] == arr[j]) {
                			for (int k = j; k < size - 1; k++) {
                    			arr[k] = arr[k + 1];
                			}
                			size--;
            			} else {
                			j++;
            			}
        			}
    			}
    			printf("Da xoa cac phan tu trung lap trong mang.\n");
    			break;
                
            }
            case 13: {
            	//Sap xep va hien thi so chan dung truoc, so le dung sau
    			int temp;
    			for (int i = 0; i < size; i++) {
        			for (int j = i + 1; j < size; j++) {
            			if (arr[i] % 2 == 1 && arr[j] % 2 == 0) {
                			temp = arr[i];
                			arr[i] = arr[j];
                			arr[j] = temp;
            			}
        			}
    			}
    			printf("Mang sau khi sap xep so chan truoc, so le sau: ");
    			for (int i = 0; i < size; i++) {
        			printf("%d ", arr[i]);
    			}
    			printf("\n");
   	 			break;
				}
            case 14: {
                // Ðao nguoc mang
                for (int i = 0, j = size - 1; i < j; i++, j--) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 15: {
            	// thoat chuong trinh
                printf("Ket thuc chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le!\n");
                break;
            }
        }
    } while (choice != 15);

    return 0;
}





