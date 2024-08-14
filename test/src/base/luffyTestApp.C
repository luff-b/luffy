//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "luffyTestApp.h"
#include "luffyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
luffyTestApp::validParams()
{
  InputParameters params = luffyApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

luffyTestApp::luffyTestApp(InputParameters parameters) : MooseApp(parameters)
{
  luffyTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

luffyTestApp::~luffyTestApp() {}

void
luffyTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  luffyApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"luffyTestApp"});
    Registry::registerActionsTo(af, {"luffyTestApp"});
  }
}

void
luffyTestApp::registerApps()
{
  registerApp(luffyApp);
  registerApp(luffyTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
luffyTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  luffyTestApp::registerAll(f, af, s);
}
extern "C" void
luffyTestApp__registerApps()
{
  luffyTestApp::registerApps();
}
