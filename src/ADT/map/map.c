#include "map.h"
#include "..\mesinkata\mesinkata.h"

void CreateEmptyM(Map *m){
    m->Count = Nol;
}

boolean IsEmptyM(Map m){
    return m.Count == 0;
}

boolean IsFullM(Map m){
    return m.Count == MaxEl;
}

valuetype Value(Map m, Produk k){
    address i = 0;

    while(i < m.Count){
        if(strCmpr(m.Elements[i].Key, k)){
            return m.Elements[i].Value;
        }
        i++;
    }
    return Undefined;
}

void Insert(Map *m, Produk k, valuetype v){
    if(IsMemberM(*m, k)){
        valuetype a = Value(*m, k);
        Delete(m, k);
        Insert(m, k, a + 1);
    } else {
        strCopy(m->Elements[m->Count].Key, k);
        m->Elements[m->Count].Value = 1;
        m->Count++;
    }
}

void Delete(Map *m, Produk k){
    if(!IsMemberM(*m, k)) return;

    address i = 0, iterator;

    while(i < m->Count){
        if(strCmpr(m->Elements[i].Key, k)){
            break;
        }
        i++;
    }
    for(iterator = (i + 1); iterator <  m->Count; iterator++){
        strCopy(m->Elements[iterator - 1].Key, m->Elements[iterator].Key);
        m->Elements[iterator - 1].Value = m->Elements[iterator].Value;
    }
    m->Count--;
}

boolean IsMemberM(Map m, Produk k){
    address i = 0;
    while(i < m.Count){
        if(strCmpr(m.Elements[i].Key, k)) return true;
        i++;
    }

    return false;
}

void ChangeVal(Map *m, Produk k, valuetype v){
    for(int i = 0; i < m->Count; i++){
        if(strCmpr(m->Elements[i].Key, k)){
            int jumlah = m->Elements[i].Value;
            if(m->Elements[i].Value + v >= 0){
                m->Elements[i].Value += v;
                if(m->Elements[i].Value == 0){
                    Delete(m, k);
                } else if(m->Elements[i].Value > jumlah){
                    printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", v, k);
                }  else {
                    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", v - (v * 2), k);
                }
            } else {
                printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", m->Elements[i].Value, m->Elements[i].Key);
                return;
            }
            break;
        }
    }
}

void DisplayMap(Map m){
    if(m.Count == 0){
        return;
    }
    for(int i = 0; i < m.Count; i++){
        printf("%s %d\n", m.Elements[i].Key, m.Elements[i].Value);
    }
}