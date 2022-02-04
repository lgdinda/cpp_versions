//
// Created by dstankiewicz on 31/01/2022.
//

#ifndef CPP_VERSIONS_CPP14_H
#define CPP_VERSIONS_CPP14_H

#include <vector>

void SmallImprovements();
auto ProveAutomaticReturnTypeDeduction();
void RelaxedConstexprFunctions();
void TemplateVariables();

[[deprecated("DoSomething() is inefficient. Use DoSomethingBetter() instead")]]
void DoSomething();
void DoSomethingBetter();
void DeprecatedAttribute();



#endif //CPP_VERSIONS_CPP14_H
