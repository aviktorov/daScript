#pragma once

namespace yzg {
    
    struct TypeDecl;
    class Context;
    struct LineInfo;
    
    struct TypeAnnotation {
        TypeAnnotation ( const string & n ) : name(n) {}
        virtual ~TypeAnnotation() {}
        virtual bool canMove() const { return true; }
        virtual bool canCopy() const { return true; }
        virtual bool isPod() const { return true; }
        virtual bool isRefType() const { return false;}
        virtual size_t getSizeOf() const { return sizeof(void *); }
        virtual TypeDecl * getField ( const string & ) const { return nullptr; }
        virtual SimNode * simulateGetField ( const string & name, Context &, const LineInfo &, SimNode * ) const
        { return nullptr; };
        string  name;
    };
    
}
