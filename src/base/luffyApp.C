#include "luffyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
luffyApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

luffyApp::luffyApp(InputParameters parameters) : MooseApp(parameters)
{
  luffyApp::registerAll(_factory, _action_factory, _syntax);
}

luffyApp::~luffyApp() {}

void
luffyApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<luffyApp>(f, af, s);
  Registry::registerObjectsTo(f, {"luffyApp"});
  Registry::registerActionsTo(af, {"luffyApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
luffyApp::registerApps()
{
  registerApp(luffyApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
luffyApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  luffyApp::registerAll(f, af, s);
}
extern "C" void
luffyApp__registerApps()
{
  luffyApp::registerApps();
}
