
/* void std::vector<std::unique_ptr<EventHandler, std::default_delete<EventHandler> >,
   std::allocator<std::unique_ptr<EventHandler, std::default_delete<EventHandler> > >
   >::_M_range_insert<std::move_iterator<__gnu_cxx::__normal_iterator<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> >*, std::vector<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> >, std::allocator<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> > > > > >
   >(__gnu_cxx::__normal_iterator<std::unique_ptr<EventHandler, std::default_delete<EventHandler>
   >*, std::vector<std::unique_ptr<EventHandler, std::default_delete<EventHandler> >,
   std::allocator<std::unique_ptr<EventHandler, std::default_delete<EventHandler> > > > >,
   std::move_iterator<__gnu_cxx::__normal_iterator<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> >*, std::vector<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> >, std::allocator<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> > > > > >,
   std::move_iterator<__gnu_cxx::__normal_iterator<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> >*, std::vector<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> >, std::allocator<std::unique_ptr<EventHandler,
   std::default_delete<EventHandler> > > > > >, std::forward_iterator_tag) */

void std::
     vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>
     ::
     _M_range_insert<std::move_iterator<__gnu_cxx::__normal_iterator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>*,std::vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>>>>
               (undefined8 *param_1,long *param_2,long *param_3,long *param_4)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  
  if (param_4 == param_3) {
    return;
  }
  plVar4 = (long *)param_1[1];
  uVar9 = (long)param_4 - (long)param_3 >> 3;
  if (uVar9 <= (ulong)(param_1[2] - (long)plVar4 >> 3)) {
    uVar10 = (long)plVar4 - (long)param_2 >> 3;
    if (uVar10 <= uVar9) {
      plVar2 = param_3 + uVar10;
      plVar7 = plVar4;
      plVar3 = plVar2;
      if (param_4 != plVar2) {
        do {
          if (plVar7 != (long *)0x0) {
            lVar12 = *plVar3;
            *plVar3 = 0;
            *plVar7 = lVar12;
          }
          plVar3 = plVar3 + 1;
          plVar7 = plVar7 + 1;
        } while (param_4 != plVar3);
        plVar7 = (long *)param_1[1];
      }
      plVar7 = plVar7 + (uVar9 - uVar10);
      param_1[1] = plVar7;
      plVar3 = param_2;
      if (plVar4 != param_2) {
        do {
          if (plVar7 != (long *)0x0) {
            lVar12 = *plVar3;
            *plVar3 = 0;
            *plVar7 = lVar12;
          }
          plVar3 = plVar3 + 1;
          plVar7 = plVar7 + 1;
        } while (plVar4 != plVar3);
        plVar7 = (long *)param_1[1];
      }
      param_1[1] = plVar7 + uVar10;
      lVar12 = (long)plVar2 - (long)param_3 >> 3;
      if (lVar12 < 1) {
        return;
      }
      do {
        lVar1 = *param_3;
        *param_3 = 0;
        plVar4 = (long *)*param_2;
        *param_2 = lVar1;
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar4 + 0x18))();
        }
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      return;
    }
    plVar3 = plVar4 + -uVar9;
    plVar2 = plVar4;
    plVar7 = plVar3;
    if (plVar4 != plVar3) {
      do {
        if (plVar2 != (long *)0x0) {
          lVar12 = *plVar7;
          *plVar7 = 0;
          *plVar2 = lVar12;
        }
        plVar7 = plVar7 + 1;
        plVar2 = plVar2 + 1;
      } while (plVar4 != plVar7);
      plVar2 = (long *)param_1[1];
    }
    param_1[1] = plVar2 + uVar9;
    lVar12 = (long)plVar3 - (long)param_2 >> 3;
    if (0 < lVar12) {
      do {
        plVar3 = plVar3 + -1;
        plVar4 = plVar4 + -1;
        lVar1 = *plVar3;
        *plVar3 = 0;
        plVar2 = (long *)*plVar4;
        *plVar4 = lVar1;
        if (plVar2 != (long *)0x0) {
          (**(code **)(*plVar2 + 0x18))();
        }
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
    }
    if ((long)uVar9 < 1) {
      return;
    }
    do {
      lVar12 = *param_3;
      *param_3 = 0;
      plVar4 = (long *)*param_2;
      *param_2 = lVar12;
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x18))();
      }
      param_3 = param_3 + 1;
      param_2 = param_2 + 1;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    return;
  }
  plVar2 = (long *)*param_1;
  uVar10 = (long)plVar4 - (long)plVar2 >> 3;
  if (0x1fffffffffffffff - uVar10 < uVar9) {
    std::__throw_length_error("vector::_M_range_insert");
    return;
  }
  uVar11 = 0xfffffffffffffff8;
  if (uVar9 <= uVar10) {
    uVar9 = uVar10;
  }
  uVar8 = uVar10 + uVar9;
  if ((!CARRY8(uVar10,uVar9)) && (uVar8 < 0x2000000000000000)) {
    if (uVar8 == 0) {
      uVar11 = 0;
      plVar4 = (long *)0x0;
      goto LAB_00117c22;
    }
    uVar11 = uVar8 * 8;
  }
  plVar4 = operator_new(uVar11);
  plVar2 = (long *)*param_1;
LAB_00117c22:
  plVar6 = param_3;
  plVar5 = plVar2;
  plVar7 = plVar4;
  plVar3 = plVar4;
  if (plVar2 != param_2) {
    do {
      if (plVar7 != (long *)0x0) {
        lVar12 = *plVar5;
        *plVar5 = 0;
        *plVar7 = lVar12;
      }
      plVar5 = plVar5 + 1;
      plVar7 = plVar7 + 1;
    } while (plVar5 != param_2);
    plVar7 = (long *)((long)plVar4 + ((long)param_2 - (long)(plVar2 + 1) & 0xfffffffffffffff8U) + 8)
    ;
    plVar3 = plVar7;
  }
  do {
    if (plVar7 != (long *)0x0) {
      lVar12 = *plVar6;
      *plVar6 = 0;
      *plVar7 = lVar12;
    }
    plVar6 = plVar6 + 1;
    plVar7 = plVar7 + 1;
  } while (param_4 != plVar6);
  plVar2 = (long *)param_1[1];
  plVar3 = (long *)((long)plVar3 + ((long)param_4 - (long)(param_3 + 1) & 0xfffffffffffffff8U) + 8);
  plVar7 = param_2;
  plVar6 = plVar3;
  if (plVar2 != param_2) {
    do {
      if (plVar6 != (long *)0x0) {
        lVar12 = *plVar7;
        *plVar7 = 0;
        *plVar6 = lVar12;
      }
      plVar7 = plVar7 + 1;
      plVar6 = plVar6 + 1;
    } while (plVar2 != plVar7);
    plVar7 = param_2 + 1;
    param_2 = (long *)param_1[1];
    plVar3 = (long *)((long)plVar3 + ((long)plVar2 - (long)plVar7 & 0xfffffffffffffff8U) + 8);
  }
  plVar2 = (long *)*param_1;
  if (plVar2 != param_2) {
    do {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (param_2 != plVar2);
    param_2 = (long *)*param_1;
  }
  if (param_2 != (long *)0x0) {
    operator_delete(param_2);
  }
  *param_1 = plVar4;
  param_1[1] = plVar3;
  param_1[2] = (long)plVar4 + uVar11;
  return;
}



