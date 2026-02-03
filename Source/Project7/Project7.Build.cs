using UnrealBuildTool;

public class Project7 : ModuleRules
{
	public Project7(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput" ,
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
