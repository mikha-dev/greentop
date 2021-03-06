/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/UpdateExecutionReport.h"

namespace greentop {


UpdateExecutionReport::UpdateExecutionReport(const std::string& customerRef,
    const ExecutionReportStatus& status,
    const ExecutionReportErrorCode& errorCode,
    const std::string& marketId,
    const std::vector<UpdateInstructionReport>& instructionReports) :
    customerRef(customerRef),
    status(status),
    errorCode(errorCode),
    marketId(marketId),
    instructionReports(instructionReports) {
}

void UpdateExecutionReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("customerRef")) {
            customerRef = json["customerRef"].asString();
        }
        if (json.isMember("status")) {
            status = json["status"].asString();
        }
        if (json.isMember("errorCode")) {
            errorCode = json["errorCode"].asString();
        }
        if (json.isMember("marketId")) {
            marketId = json["marketId"].asString();
        }
        if (json.isMember("instructionReports")) {
            for (unsigned i = 0; i < json["instructionReports"].size(); ++i) {
                UpdateInstructionReport instructionReport;
                instructionReport.fromJson(json["instructionReports"][i]);
                instructionReports.push_back(instructionReport);
            }
        }
    }
}

Json::Value UpdateExecutionReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (customerRef != "") {
        json["customerRef"] = customerRef;
    }
    if (status.isValid()) {
        json["status"] = status.getValue();
    }
    if (errorCode.isValid()) {
        json["errorCode"] = errorCode.getValue();
    }
    if (marketId != "") {
        json["marketId"] = marketId;
    }
    if (instructionReports.size() > 0) {
        for (unsigned i = 0; i < instructionReports.size(); ++i) {
            json["instructionReports"].append(instructionReports[i].toJson());
        }
    }
    return json;
}

bool UpdateExecutionReport::isValid() const {
    return status.isValid();
}

const std::string& UpdateExecutionReport::getCustomerRef() const {
    return customerRef;
}
void UpdateExecutionReport::setCustomerRef(const std::string& customerRef) {
    this->customerRef = customerRef;
}

const ExecutionReportStatus& UpdateExecutionReport::getStatus() const {
    return status;
}
void UpdateExecutionReport::setStatus(const ExecutionReportStatus& status) {
    this->status = status;
}

const ExecutionReportErrorCode& UpdateExecutionReport::getErrorCode() const {
    return errorCode;
}
void UpdateExecutionReport::setErrorCode(const ExecutionReportErrorCode& errorCode) {
    this->errorCode = errorCode;
}

const std::string& UpdateExecutionReport::getMarketId() const {
    return marketId;
}
void UpdateExecutionReport::setMarketId(const std::string& marketId) {
    this->marketId = marketId;
}

const std::vector<UpdateInstructionReport>& UpdateExecutionReport::getInstructionReports() const {
    return instructionReports;
}
void UpdateExecutionReport::setInstructionReports(const std::vector<UpdateInstructionReport>& instructionReports) {
    this->instructionReports = instructionReports;
}


}



