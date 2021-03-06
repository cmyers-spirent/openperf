# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class BulkStartBlockGeneratorsRequest(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'ids': 'list[str]',
        'dynamic_results': 'DynamicResultsConfig'
    }

    attribute_map = {
        'ids': 'ids',
        'dynamic_results': 'dynamic_results'
    }

    def __init__(self, ids=None, dynamic_results=None):  # noqa: E501
        """BulkStartBlockGeneratorsRequest - a model defined in Swagger"""  # noqa: E501

        self._ids = None
        self._dynamic_results = None
        self.discriminator = None

        self.ids = ids
        if dynamic_results is not None:
            self.dynamic_results = dynamic_results

    @property
    def ids(self):
        """Gets the ids of this BulkStartBlockGeneratorsRequest.  # noqa: E501

        List of block generator identifiers  # noqa: E501

        :return: The ids of this BulkStartBlockGeneratorsRequest.  # noqa: E501
        :rtype: list[str]
        """
        return self._ids

    @ids.setter
    def ids(self, ids):
        """Sets the ids of this BulkStartBlockGeneratorsRequest.

        List of block generator identifiers  # noqa: E501

        :param ids: The ids of this BulkStartBlockGeneratorsRequest.  # noqa: E501
        :type: list[str]
        """
        self._ids = ids

    @property
    def dynamic_results(self):
        """Gets the dynamic_results of this BulkStartBlockGeneratorsRequest.  # noqa: E501


        :return: The dynamic_results of this BulkStartBlockGeneratorsRequest.  # noqa: E501
        :rtype: DynamicResultsConfig
        """
        return self._dynamic_results

    @dynamic_results.setter
    def dynamic_results(self, dynamic_results):
        """Sets the dynamic_results of this BulkStartBlockGeneratorsRequest.


        :param dynamic_results: The dynamic_results of this BulkStartBlockGeneratorsRequest.  # noqa: E501
        :type: DynamicResultsConfig
        """
        self._dynamic_results = dynamic_results

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(BulkStartBlockGeneratorsRequest, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, BulkStartBlockGeneratorsRequest):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
