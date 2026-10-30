
/* void std::vector<std::pair<EventHandler*, std::function<void ()> >,
   std::allocator<std::pair<EventHandler*, std::function<void ()> > >
   >::_M_emplace_back_aux<std::pair<EventHandler*, std::function<void ()> >
   >(std::pair<EventHandler*, std::function<void ()> >&&) */

void __thiscall
std::
vector<std::pair<EventHandler*,std::function<void()>>,std::allocator<std::pair<EventHandler*,std::function<void()>>>>
::_M_emplace_back_aux<std::pair<EventHandler*,std::function<void()>>>
          (vector<std::pair<EventHandler*,std::function<void()>>,std::allocator<std::pair<EventHandler*,std::function<void()>>>>
           *this,pair *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  ulong local_48;
  
  lVar5 = *(long *)(this + 8) - *(long *)this >> 3;
  if (lVar5 * -0x3333333333333333 == 0) {
    local_48 = 1;
  }
  else {
    local_48 = lVar5 * -0x6666666666666666;
    if (local_48 <= (ulong)(lVar5 * -0x3333333333333333) && lVar5 * 0x3333333333333333 != 0) {
      uVar8 = 0xfffffffffffffff0;
      local_48 = 0x666666666666666;
      goto LAB_00117727;
    }
    if (0x666666666666666 < local_48) {
      uVar8 = 0xfffffffffffffff0;
      local_48 = 0x666666666666666;
      goto LAB_00117727;
    }
  }
  uVar8 = local_48 * 0x28;
LAB_00117727:
  puVar6 = operator_new(uVar8);
  puVar11 = *(undefined8 **)(this + 8);
  puVar7 = *(undefined8 **)this;
  puVar9 = (undefined8 *)(((long)puVar11 - (long)puVar7 & 0xfffffffffffffff8U) + (long)puVar6);
  if (puVar9 != (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)param_1;
    puVar9[3] = 0;
    *puVar9 = uVar1;
    uVar1 = puVar9[1];
    uVar2 = *(undefined8 *)(param_1 + 8);
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(param_1 + 0x10) = puVar9[2];
    *(undefined8 *)(param_1 + 8) = uVar1;
    puVar9[1] = uVar2;
    puVar9[2] = uVar3;
    uVar1 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x18) = puVar9[3];
    puVar9[3] = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x20) = puVar9[4];
    puVar9[4] = uVar1;
    puVar11 = *(undefined8 **)(this + 8);
    puVar7 = *(undefined8 **)this;
  }
  if (puVar11 == puVar7) {
    puVar9 = puVar6 + 5;
  }
  else {
    puVar10 = puVar6 + 4;
    puVar4 = puVar6;
    do {
      puVar9 = puVar4;
      if (puVar9 != (undefined8 *)0x0) {
        *puVar9 = *puVar7;
        puVar10[-1] = 0;
        if ((code *)puVar7[3] != (code *)0x0) {
          (*(code *)puVar7[3])(puVar9 + 1,puVar7 + 1,2);
          *puVar10 = puVar7[4];
          puVar10[-1] = puVar7[3];
        }
      }
      puVar7 = puVar7 + 5;
      puVar10 = puVar10 + 5;
      puVar4 = puVar9 + 5;
    } while (puVar11 != puVar7);
    puVar9 = puVar9 + 10;
    puVar7 = *(undefined8 **)this;
    puVar11 = *(undefined8 **)(this + 8);
    if (puVar11 != puVar7) {
      do {
        if ((code *)puVar7[3] != (code *)0x0) {
          (*(code *)puVar7[3])(puVar7 + 1,puVar7 + 1,3);
        }
        puVar7 = puVar7 + 5;
      } while (puVar11 != puVar7);
      puVar11 = *(undefined8 **)this;
    }
  }
  if (puVar11 != (undefined8 *)0x0) {
    operator_delete(puVar11);
  }
  *(undefined8 **)(this + 8) = puVar9;
  *(undefined8 **)this = puVar6;
  *(undefined8 **)(this + 0x10) = puVar6 + local_48 * 5;
  return;
}



