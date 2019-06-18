//
// Created by raxzers on 6/16/18.
//

#include "Huffman.h"
#include <bitset>
#include <bits/stdc++.h>

void Huffman::printCodes(Huffman::MinHeapNode *root, std::string str) {
    if (!root)
        return;

    if (root->data != "$"){
        diccionario.insert(std::make_pair(root->data , str ));
        }




    printCodes(root->left, str + "1");
    printCodes(root->right, str + "0");
}

void Huffman::HuffmanCodes(std::map<char, int> refer, int size) {
    struct MinHeapNode *left, *right, *top;
    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;

    std::map <char, int> :: iterator itr;


    for (itr = refer.begin(); itr != refer.end(); ++itr)

        minHeap.push(new MinHeapNode(itr->first, itr->second));

    while (minHeap.size() != 1) {

        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();


        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

void Huffman::counter(std::string s) {
    int n = s.length();
    char char_array[n+1];
    std::strcpy(char_array, s.c_str());

    for (int i=0; i<n; i++){

        if(refer.find(char_array[i])== refer.end()){refer.insert(std::pair <char, int> (char_array[i],1));}
        else{refer[char_array[i]]+=1;}

    }
    int size = sizeof(char_array) / sizeof(char_array[0]);
    HuffmanCodes(refer,size);
}

void Huffman::comprimir(std::string s) {
    counter(s);

    comprimido = "";
    int n = s.length();
    char char_array[n+1];
    std::strcpy(char_array, s.c_str());


    for (int i=0; i<n; i++){

       comprimido +=  diccionario[s.substr(i,1)];

    }

    sizeComp = comprimido.size();
    partirCompreso();
}





template<class T1, class T2>
std::map<T2, T1> Huffman::swapPairs(std::map<T1, T2> m) {
    std::map<T2, T1> m1;

    for (auto&& item : m) {
        m1.emplace(item.second, item.first);
    }

    return m1;
}

std::string Huffman::descomprimir(int arr[16],int tan, std::map<std::string,std::string> dicci) {




    std::map<std::string ,std::string> cid= swapPairs(dicci);
    std::string s =unirCompreso(arr,tan);

    int n = s.length();
    char char_array[n+1];
    std::strcpy(char_array, s.c_str());
    std::string des ;
    std::string codig="";

    for (int i=0; i<n; i++){

        if(cid.find(codig) != cid.end()){
            des+=cid[codig];
            codig=char_array[i];
        }
        else{
            char c=char_array[i];
            codig+=c;//.char_array[i]);


        }

    }des+=cid[codig];
    return des;
}

void Huffman::partirCompreso() {
    std::bitset<32> parte;
    std::bitset<512> bit(comprimido);
    //std::cout << bit.to_string()<< std::endl;
    int bitF=0;
    for(int i=0;i<16;i++){
        for(int j=0;j<32;j++){

            parte[j]=bit[bitF];
            bitF++;
        }

        compEnt[i]=parte.to_ulong();
        parte.reset();
    }

}



std::string Huffman::unirCompreso(int arr[16],int tan) {
   std::string comprir;

    for(int i=0;i<16;i++){
        std::bitset<32> parte(arr[15-i]);
        comprir.append(parte.to_string());

    }

    return comprir.substr (512-tan,511);
}

std::string Huffman::generarArchivo() {
    boost::property_tree::ptree ptcomp,diccio,bites;

    //pone el diccionario
    for(auto elem : this->diccionario)
    {
        boost::property_tree::ptree carac;
        carac.put_value(elem.second);

        diccio.push_back(std::make_pair(elem.first,carac));

    }
    ptcomp.add_child("diccionario",diccio);



    //pone el largo
    ptcomp.put("largo",this->sizeComp);

    //pone el archivo en 16 pates de int
    for(int i =0;i<16;i++){
        boost::property_tree::ptree num;
        num.put_value(this->compEnt[i]);
        bites.push_back(std::make_pair("",num));

    }
    ptcomp.add_child("bites",bites);



    std::ostringstream buf2;
    write_json (buf2, ptcomp, false);
    std::string json2 = buf2.str();


    return json2 ;




}

std::string Huffman::descomprimir(std::string serial) {
    boost::property_tree::ptree pt;

    std::istringstream is (serial);
    boost::property_tree::read_json(is,pt);

    int largo = pt.get<int>("largo");
    int bites[16],pos;
    pos =0;


    BOOST_FOREACH(const boost::property_tree::ptree::value_type &v,
    pt.get_child("bites"))
    {

        bites[pos]=v.second.get_value<int>();
        pos++;

    }






    std::map <std::string,std::string > diccionario;
    BOOST_FOREACH(const boost::property_tree::ptree::value_type &v,
    pt.get_child("diccionario"))
    {
        diccionario.insert ( std::pair<std::string,std::string>(v.first,v.second.get_value<std::string>()) );
    }

    return descomprimir(bites,largo,diccionario);
}


