#include "CrystalLight.h"


bool CrystalLightShim::IsDesiredHeadset(std::string model, vr::PropertyContainerHandle_t container){	
	
	std::string trackingSystem = vr::VRProperties()->GetStringProperty(container, vr::Prop_TrackingSystemName_String);	

	if (model == "REF-HMD" && trackingSystem == "lighthouse") {	
		return true;
	}
	return false;

	/*

	std::string trackingSystem = vr::VRProperties()->GetStringProperty(container, vr::Prop_TrackingSystemName_String);
	std::string serialNumber = vr::VRProperties()->GetStringProperty(container, vr::Prop_SerialNumber_String);

	// Primary detection: EDID vendor/product ID (PVR 53826, Product 4121)
	int32_t edidVendor = vr::VRProperties()->GetInt32Property(container, vr::Prop_EdidVendorID_Int32);
	int32_t edidProduct = vr::VRProperties()->GetInt32Property(container, vr::Prop_EdidProductID_Int32);

	DriverLog("*** Crystal Light edidVendor: %d, edidProduct: %d, model: %s", edidVendor, edidProduct, model.c_str());

	if(edidVendor == 53826 && edidProduct == 4121 && trackingSystem == "lighthouse"){
		DriverLog("Crystal Light detected via EDID (PVR 53826:4121) + lighthouse tracking");
		return true;
	}

	// Fallback: Check for Crystal model name with lighthouse tracking
	if(model == "Crystal" && trackingSystem == "lighthouse"){
		DriverLog("Crystal Light detected via model name");
		return true;
	}

	// Fallback: Crystal Light may report empty model string
	// Check for lighthouse tracking with LHR- serial prefix (lighthouse headset)
	if((model.empty() || model == "") && trackingSystem == "lighthouse" && serialNumber.find("LHR-") == 0){
		DriverLog("Crystal Light detected via empty model + lighthouse tracking + LHR serial");
		return true;
	}

	return false;
	*/
}

Config::BaseHeadsetConfig& CrystalLightShim::GetConfig(){
	return driverConfig.crystalLight;
}

Config::BaseHeadsetConfig& CrystalLightShim::GetConfigOld(){
	return driverConfigOld.crystalLight;
}
