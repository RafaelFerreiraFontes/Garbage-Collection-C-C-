#include <map>
#include <cstdio>
#include <cstdlib>


void _atualizarED(void *ed,bool command);

template <class type>
struct GCtype
{
    type* ed = NULL;//endereco de memoria.

    //Funcao malloc2, que aloca a area de memoria na struct.
    void malloc2(size_t size)
    {
       if(ed == NULL)
        {
            ed = (type *) malloc(sizeof(type*) * size);
            _atualizarED(ed,true);
        }
       else
       {
         _atualizarED(ed,false);  
         ed = (type *) malloc(sizeof(type) * size);
         _atualizarED(ed,true);  
       }
    }

    //Funcao que atribui o valor do campo ed para outro ponteiro.
    void atribuir(type *a)
    {
       if(a != NULL)
       {
            if(ed == NULL)
            {
                ed = a;
                _atualizarED(a,true);
            }
            else
            {
                _atualizarED(ed,false);
                ed = a;
                _atualizarED(ed,true);
            }
       }
       else
       {
          if(ed != NULL)
            _atualizarED(ed,false);
       }
    }

    //Funcao atribui um valor ao campo ed.
    void atribuir2(type a)
    {
        if(ed != NULL)
        {
            *ed = a;
        }
    }
};

//Lista de enderecos.
map<void *,int> _EDList;

//Funcao atualiza a lista de enderecos.
void _atualizarED(void *ed,bool command)
{
    if(ed == NULL)
      return;
      
    if(command)
    {
        _EDList[ed]++;
    }
    else
    {
       _EDList[ed]--;

       if(_EDList[ed] <= 0)
       {    
           _EDList.erase(ed);
           cout << "Area de memoria " << ed << " liberada"<<endl;
           free(ed);
       } 
    }
}

//Funcao mostra as areas de memorias e quantidade de referencias.
void Dump()
{
  map<void *,int>::iterator it;   

  for(it = _EDList.begin(); it != _EDList.end();it++)
  {
      cout << it->first << " => " << it->second << endl;
  }
}
